/* SoundMenuIntegration.c generated by valac 0.11.7, the Vala compiler
 * generated from SoundMenuIntegration.vala, do not modify */

/*using Indicate;

public class BeatBox.SoundMenuIntegration : GLib.Object {
private LibraryManager lm;
private LibraryWindow lw;
private uint watch;
private Indicate.Server server;

public SoundMenuIntegration(LibraryManager lmm, LibraryWindow lww) {
lm = lmm;
lw = lww;

watch = Bus.watch_name(BusType.SESSION,
                      "org.ayatana.indicator.sound",
                      BusNameWatcherFlags.NONE,
                      on_name_appeared,
                      on_name_vanished);
}

private void on_name_appeared(DBusConnection conn, string name) {
stdout.printf("name %s appeared\n", name);

/* set up the server to connect to music.beatbox dbus *
server = Indicate.Server.ref_default();
server.set("type", "music.beatbox");
//server.set_desktop_file(GLib.Path.build_filename(Config.DATADIR, "applications", "beatbox.desktop", null));
server.show();
}

private void on_name_vanished(DBusConnection conn, string name) {
stdout.printf("name %s vanished\n", name);

if(server != null)
server.hide();
}
}
*/

#include <glib.h>
#include <glib-object.h>






