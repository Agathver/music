/*
 * Copyright (C) 2011-2012 Lucas Baudin <xapantu@gmail.com>
 *
 * Author: Zeeshan Ali (Khattak) <zeeshanak@gnome.org> (from Rygel)
 *
 * This file is part of Marlin.
 *
 * Marlin is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Marlin is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


public class Noise.Plugins.Interface : Object {
    Manager manager;

    public enum Hook {
        CONTEXT,
        SIDEBAR,
        MAIN_MENU,
        ADDONS_MENU,
        BOTTOMBAR,
        TOOLBAR,
        SOURCE_VIEW,
        SETTINGS_DIALOG,
        WINDOW
    }

    public delegate void HookFunction ();
    public delegate void HookFunctionArg (Object object);
    
    public Gtk.Notebook context {internal set; get; }
    public Gtk.Notebook sidebar {internal set; get; }
    public Gtk.Notebook bottombar {internal set; get; }
    public Gtk.Application scratch_app {internal set; get; }
    public Gtk.Menu main_menu {private set; get; }
    public Gtk.Menu addons_menu {private set; get; }
    public Gtk.Toolbar toolbar {internal set; get; }
    public Gtk.Window window {private set; get; }
    public string set_name {internal set; get; }
    public string? argument {internal set; get; }

    public unowned List<Gtk.TextView> all_source_view { private set; get; }

    public Interface (Manager manager) {
        this.manager = manager;
        all_source_view = new List<Gtk.TextView>();

        manager.hook_main_menu.connect( (m) => {
            main_menu = m;
        });
        manager.hook_addons_menu.connect( (m) => {
            addons_menu = m;
        });
        manager.hook_new_window.connect( (m) => {
            window = m;
        });
        manager.hook_notebook_bottom.connect( (m) => {
            bottombar = m;
        });
        manager.hook_source_view.connect( (m) => {
            all_source_view.append(m);
        });
    }
    
    public void register_function_arg (Hook hook, HookFunctionArg hook_function) {
        switch (hook) {
        case Hook.SOURCE_VIEW:
            manager.hook_source_view.connect_after ((m) => {
                hook_function(m);
            });
            foreach (var source_view in all_source_view) {
                hook_function (source_view);
            }
            break;
        case Hook.SETTINGS_DIALOG:
            manager.hook_preferences_dialog.connect_after ( (d) => {
                hook_function (d);
            });
            break;
        }
    }
    
    public void register_function_signal (Hook hook, string signal_name, Object obj) {
        switch(hook) {
        case Hook.BOTTOMBAR:
            manager.hook_notebook_bottom.connect_after (() => {
                Signal.emit_by_name (obj, signal_name);
            });
            if(bottombar != null) {
                Signal.emit_by_name (obj, signal_name);
            }
            break;
        }
    }
    
    public void register_function (Hook hook, HookFunction hook_function) {
        switch(hook) {
        case Hook.CONTEXT:
            manager.hook_notebook_context.connect_after (() => {
                hook_function();
            });
            if (context != null) {
                hook_function ();
            }
            break;
        case Hook.SIDEBAR:
            manager.hook_notebook_sidebar.connect_after (() => {
                hook_function();
            });
            if (sidebar != null) {
                hook_function ();
            }
            break;
        case Hook.TOOLBAR:
            manager.hook_toolbar.connect_after (() => {
                hook_function();
            });
            if (toolbar != null) {
                hook_function ();
            }
            break;
        case Hook.BOTTOMBAR:
            manager.hook_notebook_bottom.connect_after (() => {
                hook_function();
            });
            if (bottombar != null) {
                hook_function ();
            }
            break;
        case Hook.MAIN_MENU:
            manager.hook_main_menu.connect_after (() => {
                hook_function();
            });
            if (main_menu != null) {
                hook_function ();
            }
            break;
        case Hook.ADDONS_MENU:
            manager.hook_addons_menu.connect_after (() => {
                hook_function();
            });
            if (addons_menu != null) {
                hook_function ();
            }
            break;
        case Hook.WINDOW:
            manager.hook_new_window.connect_after (() => {
                hook_function ();
            });
            if (window != null) {
                hook_function ();
            }
            break;
        }
    }
    
}


public class Noise.Plugins.Manager : Object
{
    public signal void hook_main_menu (Gtk.Menu menu);
    public signal void hook_toolbar ();
    public signal void hook_set_arg (string set_name, string? set_arg);
    public signal void hook_notebook_bottom (Gtk.Notebook notebook);
    public signal void hook_source_view(Gtk.TextView view);
    public signal void hook_new_window(Gtk.Window window);
    public signal void hook_preferences_dialog(Gtk.Dialog dialog);
    public signal void hook_toolbar_context_menu(Gtk.Menu menu);

    Peas.Engine engine;
    Peas.ExtensionSet exts;
        
    public Gtk.Toolbar toolbar { set { plugin_iface.toolbar = value; } }
    public Gtk.Application scratch_app { set { plugin_iface.scratch_app = value;  }}

    //[CCode (cheader_filename = "libpeas/libpeas.h", cname = "peas_extension_set_foreach")]
    //extern static void peas_extension_set_foreach (Peas.ExtensionSet extset, Peas.ExtensionSetForeachFunc option, void* data);

    GLib.Settings settings;
    string settings_field;
    
    public Noise.Plugins.Interface plugin_iface { private set; public get; }

    public Manager(GLib.Settings s, string f, string d, string? e, string? argument_set)
    {
        settings = s;
        settings_field = f;

        plugin_iface = new Noise.Plugins.Interface (this);
        plugin_iface.argument = argument_set;
        plugin_iface.set_name = e ?? "noise";

        /* Let's init the engine */
        engine = Peas.Engine.get_default ();
        engine.enable_loader ("python");
        engine.enable_loader ("gjs");
        engine.add_search_path (d, null);
        settings.bind("plugins-enabled", engine, "loaded-plugins", SettingsBindFlags.DEFAULT);
        
        /* Our extension set */
        Parameter param = Parameter();
        param.value = plugin_iface;
        param.name = "object";
        exts = new Peas.ExtensionSet (engine, typeof(Peas.Activatable), "object", plugin_iface, null);

        exts.extension_added.connect( (info, ext) => {  
                ((Peas.Activatable)ext).activate();
        });
        exts.extension_removed.connect(on_extension_removed);
        
        exts.foreach (on_extension_added);
        
    }
    
    public Gtk.Widget get_view () {
        var view = new PeasGtk.PluginManager (engine);
        var bottom_box = view.get_children ().nth_data (1) as Gtk.Box;
        assert(bottom_box != null);
        bottom_box.get_children ().nth_data(0).no_show_all = true;
        bottom_box.get_children ().nth_data(0).visible = false;
        return view;
    }
    
    void on_extension_added(Peas.ExtensionSet set, Peas.PluginInfo info, Peas.Extension extension) {
        var core_list = engine.get_plugin_list ().copy ();
        for (int i = 0; i < core_list.length(); i++) {
            string module = core_list.nth_data (i).get_module_name ();
            if (module == info.get_module_name ()) 
                ((Peas.Activatable)extension).activate();
            /* Enable plugin set */
            else if (module == plugin_iface.set_name) {
                debug ("Loaded %s", module);
                ((Peas.Activatable)extension).activate();
            }
            else
                ((Peas.Activatable)extension).deactivate();
        }
    }
    void on_extension_removed(Peas.PluginInfo info, Object extension) {
        ((Peas.Activatable)extension).deactivate();
    }

    public void hook_app(Gtk.Application menu)
    {
    }
    
    public Gtk.Notebook context { set { plugin_iface.context = value; } }
    public signal void hook_notebook_context (); 
    
    public Gtk.Notebook sidebar { set { plugin_iface.sidebar = value; } }
    public signal void hook_notebook_sidebar (); 
    
    public signal void hook_addons_menu(Gtk.Menu menu);
    
    public void hook_example(string arg)
    {
    }
}

