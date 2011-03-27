/* ToolButtonWithMenu.c generated by valac 0.11.7, the Vala compiler
 * generated from ToolButtonWithMenu.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gdk/gdk.h>


#define TYPE_TOOL_BUTTON_WITH_MENU (tool_button_with_menu_get_type ())
#define TOOL_BUTTON_WITH_MENU(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TOOL_BUTTON_WITH_MENU, ToolButtonWithMenu))
#define TOOL_BUTTON_WITH_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TOOL_BUTTON_WITH_MENU, ToolButtonWithMenuClass))
#define IS_TOOL_BUTTON_WITH_MENU(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TOOL_BUTTON_WITH_MENU))
#define IS_TOOL_BUTTON_WITH_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TOOL_BUTTON_WITH_MENU))
#define TOOL_BUTTON_WITH_MENU_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TOOL_BUTTON_WITH_MENU, ToolButtonWithMenuClass))

typedef struct _ToolButtonWithMenu ToolButtonWithMenu;
typedef struct _ToolButtonWithMenuClass ToolButtonWithMenuClass;
typedef struct _ToolButtonWithMenuPrivate ToolButtonWithMenuPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _ToolButtonWithMenu {
	GtkToggleToolButton parent_instance;
	ToolButtonWithMenuPrivate * priv;
	GtkMenu* menu;
};

struct _ToolButtonWithMenuClass {
	GtkToggleToolButtonClass parent_class;
};

struct _ToolButtonWithMenuPrivate {
	GtkPositionType _menu_orientation;
};


static gpointer tool_button_with_menu_parent_class = NULL;

GType tool_button_with_menu_get_type (void) G_GNUC_CONST;
#define TOOL_BUTTON_WITH_MENU_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_TOOL_BUTTON_WITH_MENU, ToolButtonWithMenuPrivate))
enum  {
	TOOL_BUTTON_WITH_MENU_DUMMY_PROPERTY,
	TOOL_BUTTON_WITH_MENU_MENU_ORIENTATION
};
ToolButtonWithMenu* tool_button_with_menu_construct (GType object_type, GtkImage* image, const gchar* label, GtkMenu* _menu, GtkPositionType menu_orientation);
void tool_button_with_menu_set_menu_orientation (ToolButtonWithMenu* self, GtkPositionType value);
static void _lambda12_ (ToolButtonWithMenu* self);
static void __lambda12__gtk_menu_shell_deactivate (GtkMenuShell* _sender, gpointer self);
static gboolean tool_button_with_menu_on_mnemonic_activate (ToolButtonWithMenu* self, gboolean group_cycling);
static gboolean _tool_button_with_menu_on_mnemonic_activate_gtk_widget_mnemonic_activate (GtkWidget* _sender, gboolean group_cycling, gpointer self);
void tool_button_with_menu_popdown_menu (ToolButtonWithMenu* self);
static void _tool_button_with_menu_popdown_menu_gtk_menu_shell_deactivate (GtkMenuShell* _sender, gpointer self);
void tool_button_with_menu_popup_menu (ToolButtonWithMenu* self, GdkEventButton* ev);
static void tool_button_with_menu_get_menu_position (ToolButtonWithMenu* self, GtkMenu* menu, gint* x, gint* y, gboolean* push_in);
static void _tool_button_with_menu_get_menu_position_gtk_menu_position_func (GtkMenu* menu, gint* x, gint* y, gboolean* push_in, gpointer self);
static void tool_button_with_menu_real_show_all (GtkWidget* base);
GtkPositionType tool_button_with_menu_get_menu_orientation (ToolButtonWithMenu* self);
static void tool_button_with_menu_finalize (GObject* obj);
static void _vala_tool_button_with_menu_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_tool_button_with_menu_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _lambda12_ (ToolButtonWithMenu* self) {
	gtk_toggle_tool_button_set_active ((GtkToggleToolButton*) self, FALSE);
}


static void __lambda12__gtk_menu_shell_deactivate (GtkMenuShell* _sender, gpointer self) {
	_lambda12_ (self);
}


static gboolean _tool_button_with_menu_on_mnemonic_activate_gtk_widget_mnemonic_activate (GtkWidget* _sender, gboolean group_cycling, gpointer self) {
	gboolean result;
	result = tool_button_with_menu_on_mnemonic_activate (self, group_cycling);
	return result;
}


static void _tool_button_with_menu_popdown_menu_gtk_menu_shell_deactivate (GtkMenuShell* _sender, gpointer self) {
	tool_button_with_menu_popdown_menu (self);
}


ToolButtonWithMenu* tool_button_with_menu_construct (GType object_type, GtkImage* image, const gchar* label, GtkMenu* _menu, GtkPositionType menu_orientation) {
	ToolButtonWithMenu * self = NULL;
	GtkLabel* _tmp0_ = NULL;
	GtkLabel* _tmp1_;
	GtkWidget* _tmp2_ = NULL;
	GtkMenu* _tmp3_;
	g_return_val_if_fail (image != NULL, NULL);
	g_return_val_if_fail (label != NULL, NULL);
	g_return_val_if_fail (_menu != NULL, NULL);
	self = (ToolButtonWithMenu*) g_object_new (object_type, NULL);
	tool_button_with_menu_set_menu_orientation (self, menu_orientation);
	gtk_tool_button_set_icon_widget ((GtkToolButton*) self, (GtkWidget*) image);
	_tmp0_ = (GtkLabel*) gtk_label_new (label);
	_tmp1_ = g_object_ref_sink (_tmp0_);
	gtk_tool_button_set_label_widget ((GtkToolButton*) self, (GtkWidget*) _tmp1_);
	_g_object_unref0 (_tmp1_);
	_tmp2_ = gtk_tool_button_get_label_widget ((GtkToolButton*) self);
	gtk_label_set_use_underline (GTK_LABEL (_tmp2_), TRUE);
	g_object_set ((GtkWidget*) self, "can-focus", TRUE, NULL);
	gtk_tool_item_set_tooltip_text ((GtkToolItem*) self, "Menu");
	_tmp3_ = _g_object_ref0 (_menu);
	_g_object_unref0 (self->menu);
	self->menu = _tmp3_;
	gtk_menu_attach_to_widget (self->menu, (GtkWidget*) self, NULL);
	g_signal_connect_object ((GtkMenuShell*) self->menu, "deactivate", (GCallback) __lambda12__gtk_menu_shell_deactivate, self, 0);
	g_signal_connect_object ((GtkWidget*) self, "mnemonic-activate", (GCallback) _tool_button_with_menu_on_mnemonic_activate_gtk_widget_mnemonic_activate, self, 0);
	g_signal_connect_object ((GtkMenuShell*) self->menu, "deactivate", (GCallback) _tool_button_with_menu_popdown_menu_gtk_menu_shell_deactivate, self, 0);
	return self;
}


static gboolean tool_button_with_menu_on_mnemonic_activate (ToolButtonWithMenu* self, gboolean group_cycling) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	if (!group_cycling) {
		gtk_widget_activate ((GtkWidget*) self);
	} else {
		gboolean _tmp0_;
		g_object_get ((GtkWidget*) self, "can-focus", &_tmp0_, NULL);
		if (_tmp0_) {
			gtk_widget_grab_focus ((GtkWidget*) self);
		}
	}
	result = TRUE;
	return result;
}


static void _tool_button_with_menu_get_menu_position_gtk_menu_position_func (GtkMenu* menu, gint* x, gint* y, gboolean* push_in, gpointer self) {
	tool_button_with_menu_get_menu_position (self, menu, x, y, push_in);
}


void tool_button_with_menu_popup_menu (ToolButtonWithMenu* self, GdkEventButton* ev) {
	guint _tmp0_ = 0U;
	guint32 _tmp1_ = 0U;
	GtkWidget* _tmp3_ = NULL;
	GtkWidget* _tmp4_;
	gboolean _tmp5_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	if (ev == NULL) {
		_tmp0_ = (guint) 0;
	} else {
		_tmp0_ = (*ev).button;
	}
	if (ev == NULL) {
		guint32 _tmp2_;
		_tmp2_ = gtk_get_current_event_time ();
		_tmp1_ = _tmp2_;
	} else {
		_tmp1_ = (*ev).time;
	}
	gtk_menu_popup (self->menu, NULL, NULL, _tool_button_with_menu_get_menu_position_gtk_menu_position_func, self, _tmp0_, _tmp1_);
	__finally81:
	g_object_get (self->menu, "attach-widget", &_tmp3_, NULL);
	_tmp4_ = _tmp3_;
	_tmp5_ = _tmp4_ != NULL;
	_g_object_unref0 (_tmp4_);
	if (_tmp5_) {
		GtkWidget* _tmp6_ = NULL;
		GtkWidget* _tmp7_;
		g_object_get (self->menu, "attach-widget", &_tmp6_, NULL);
		_tmp7_ = _tmp6_;
		gtk_widget_set_state (_tmp7_, GTK_STATE_SELECTED);
		_g_object_unref0 (_tmp7_);
	}
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


void tool_button_with_menu_popdown_menu (ToolButtonWithMenu* self) {
	GtkWidget* _tmp0_ = NULL;
	GtkWidget* _tmp1_;
	gboolean _tmp2_;
	g_return_if_fail (self != NULL);
	gtk_menu_popdown (self->menu);
	g_object_get (self->menu, "attach-widget", &_tmp0_, NULL);
	_tmp1_ = _tmp0_;
	_tmp2_ = _tmp1_ != NULL;
	_g_object_unref0 (_tmp1_);
	if (_tmp2_) {
		GtkWidget* _tmp3_ = NULL;
		GtkWidget* _tmp4_;
		g_object_get (self->menu, "attach-widget", &_tmp3_, NULL);
		_tmp4_ = _tmp3_;
		gtk_widget_set_state (_tmp4_, GTK_STATE_NORMAL);
		_g_object_unref0 (_tmp4_);
	}
}


static void tool_button_with_menu_real_show_all (GtkWidget* base) {
	ToolButtonWithMenu * self;
	self = (ToolButtonWithMenu*) base;
	GTK_WIDGET_CLASS (tool_button_with_menu_parent_class)->show_all ((GtkWidget*) GTK_TOGGLE_TOOL_BUTTON (self));
	gtk_widget_show_all ((GtkWidget*) self->menu);
}


static void tool_button_with_menu_get_menu_position (ToolButtonWithMenu* self, GtkMenu* menu, gint* x, gint* y, gboolean* push_in) {
	gint _x = 0;
	gint _y = 0;
	gboolean _push_in = FALSE;
	gboolean _tmp0_ = FALSE;
	GtkWidget* _tmp1_ = NULL;
	GtkWidget* _tmp2_;
	gboolean _tmp3_;
	GtkWidget* _tmp7_ = NULL;
	GtkWidget* _tmp8_;
	GdkWindow* _tmp9_ = NULL;
	gint _tmp10_;
	gint _tmp11_;
	GtkAllocation allocation = {0};
	GtkWidget* _tmp12_ = NULL;
	GtkWidget* _tmp13_;
	GtkAllocation _tmp14_ = {0};
	gint width = 0;
	gint height = 0;
	gint _tmp15_;
	gint _tmp16_;
	GtkWidget* _tmp17_ = NULL;
	GtkWidget* _tmp18_;
	GdkScreen* _tmp19_ = NULL;
	gint _tmp20_;
	gboolean _tmp21_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (menu != NULL);
	g_object_get (menu, "attach-widget", &_tmp1_, NULL);
	_tmp2_ = _tmp1_;
	_tmp3_ = _tmp2_ == NULL;
	_g_object_unref0 (_tmp2_);
	if (_tmp3_) {
		_tmp0_ = TRUE;
	} else {
		GtkWidget* _tmp4_ = NULL;
		GtkWidget* _tmp5_;
		GdkWindow* _tmp6_ = NULL;
		g_object_get (menu, "attach-widget", &_tmp4_, NULL);
		_tmp5_ = _tmp4_;
		_tmp6_ = gtk_widget_get_window (_tmp5_);
		_tmp0_ = _tmp6_ == NULL;
		_g_object_unref0 (_tmp5_);
	}
	if (_tmp0_) {
		_x = 0;
		_y = 0;
		_push_in = TRUE;
		if (x) {
			*x = _x;
		}
		if (y) {
			*y = _y;
		}
		if (push_in) {
			*push_in = _push_in;
		}
		return;
	}
	g_object_get (menu, "attach-widget", &_tmp7_, NULL);
	_tmp8_ = _tmp7_;
	_tmp9_ = gtk_widget_get_window (_tmp8_);
	gdk_window_get_origin (_tmp9_, &_tmp10_, &_tmp11_);
	_x = _tmp10_;
	_y = _tmp11_;
	_g_object_unref0 (_tmp8_);
	g_object_get (menu, "attach-widget", &_tmp12_, NULL);
	_tmp13_ = _tmp12_;
	gtk_widget_get_allocation (_tmp13_, &_tmp14_);
	allocation = _tmp14_;
	_g_object_unref0 (_tmp13_);
	_x = _x + allocation.x;
	_y = _y + allocation.y;
	gtk_widget_get_size_request ((GtkWidget*) menu, &_tmp15_, &_tmp16_);
	width = _tmp15_;
	height = _tmp16_;
	g_object_get (menu, "attach-widget", &_tmp17_, NULL);
	_tmp18_ = _tmp17_;
	_tmp19_ = gtk_widget_get_screen (_tmp18_);
	_tmp20_ = gdk_screen_get_height (_tmp19_);
	_tmp21_ = (_y + height) >= _tmp20_;
	_g_object_unref0 (_tmp18_);
	if (_tmp21_) {
		_y = _y - height;
	} else {
		_y = _y + allocation.height;
	}
	_push_in = TRUE;
	if (x) {
		*x = _x;
	}
	if (y) {
		*y = _y;
	}
	if (push_in) {
		*push_in = _push_in;
	}
}


GtkPositionType tool_button_with_menu_get_menu_orientation (ToolButtonWithMenu* self) {
	GtkPositionType result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_menu_orientation;
	return result;
}


void tool_button_with_menu_set_menu_orientation (ToolButtonWithMenu* self, GtkPositionType value) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	if (value == GTK_POS_TOP) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = value == GTK_POS_BOTTOM;
	}
	if (_tmp0_) {
		value = GTK_POS_LEFT;
	}
	self->priv->_menu_orientation = value;
	g_object_notify ((GObject *) self, "menu-orientation");
}


static void tool_button_with_menu_class_init (ToolButtonWithMenuClass * klass) {
	tool_button_with_menu_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (ToolButtonWithMenuPrivate));
	GTK_WIDGET_CLASS (klass)->show_all = tool_button_with_menu_real_show_all;
	G_OBJECT_CLASS (klass)->get_property = _vala_tool_button_with_menu_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_tool_button_with_menu_set_property;
	G_OBJECT_CLASS (klass)->finalize = tool_button_with_menu_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), TOOL_BUTTON_WITH_MENU_MENU_ORIENTATION, g_param_spec_enum ("menu-orientation", "menu-orientation", "menu-orientation", GTK_TYPE_POSITION_TYPE, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void tool_button_with_menu_instance_init (ToolButtonWithMenu * self) {
	self->priv = TOOL_BUTTON_WITH_MENU_GET_PRIVATE (self);
}


static void tool_button_with_menu_finalize (GObject* obj) {
	ToolButtonWithMenu * self;
	self = TOOL_BUTTON_WITH_MENU (obj);
	_g_object_unref0 (self->menu);
	G_OBJECT_CLASS (tool_button_with_menu_parent_class)->finalize (obj);
}


GType tool_button_with_menu_get_type (void) {
	static volatile gsize tool_button_with_menu_type_id__volatile = 0;
	if (g_once_init_enter (&tool_button_with_menu_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ToolButtonWithMenuClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tool_button_with_menu_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ToolButtonWithMenu), 0, (GInstanceInitFunc) tool_button_with_menu_instance_init, NULL };
		GType tool_button_with_menu_type_id;
		tool_button_with_menu_type_id = g_type_register_static (GTK_TYPE_TOGGLE_TOOL_BUTTON, "ToolButtonWithMenu", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&tool_button_with_menu_type_id__volatile, tool_button_with_menu_type_id);
	}
	return tool_button_with_menu_type_id__volatile;
}


static void _vala_tool_button_with_menu_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	ToolButtonWithMenu * self;
	self = TOOL_BUTTON_WITH_MENU (object);
	switch (property_id) {
		case TOOL_BUTTON_WITH_MENU_MENU_ORIENTATION:
		g_value_set_enum (value, tool_button_with_menu_get_menu_orientation (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_tool_button_with_menu_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	ToolButtonWithMenu * self;
	self = TOOL_BUTTON_WITH_MENU (object);
	switch (property_id) {
		case TOOL_BUTTON_WITH_MENU_MENU_ORIENTATION:
		tool_button_with_menu_set_menu_orientation (self, g_value_get_enum (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



