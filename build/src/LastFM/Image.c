/* Image.c generated by valac 0.11.7, the Vala compiler
 * generated from Image.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <gio/gio.h>
#include <stdio.h>


#define LAST_FM_TYPE_IMAGE (last_fm_image_get_type ())
#define LAST_FM_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LAST_FM_TYPE_IMAGE, LastFMImage))
#define LAST_FM_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LAST_FM_TYPE_IMAGE, LastFMImageClass))
#define LAST_FM_IS_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LAST_FM_TYPE_IMAGE))
#define LAST_FM_IS_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LAST_FM_TYPE_IMAGE))
#define LAST_FM_IMAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LAST_FM_TYPE_IMAGE, LastFMImageClass))

typedef struct _LastFMImage LastFMImage;
typedef struct _LastFMImageClass LastFMImageClass;
typedef struct _LastFMImagePrivate LastFMImagePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _LastFMImage {
	GObject parent_instance;
	LastFMImagePrivate * priv;
};

struct _LastFMImageClass {
	GObjectClass parent_class;
};

struct _LastFMImagePrivate {
	gchar* _url;
	GdkPixbuf* _image;
	gint* _size;
	gint _size_length1;
	gint __size_size_;
};


static gpointer last_fm_image_parent_class = NULL;
static gint last_fm_image_default_size;
static gint last_fm_image_default_size = 500;

GType last_fm_image_get_type (void) G_GNUC_CONST;
#define LAST_FM_IMAGE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), LAST_FM_TYPE_IMAGE, LastFMImagePrivate))
enum  {
	LAST_FM_IMAGE_DUMMY_PROPERTY,
	LAST_FM_IMAGE_URL,
	LAST_FM_IMAGE_IMAGE
};
LastFMImage* last_fm_image_new_basic (void);
LastFMImage* last_fm_image_construct_basic (GType object_type);
LastFMImage* last_fm_image_new_with_url (const gchar* url, gboolean generate);
LastFMImage* last_fm_image_construct_with_url (GType object_type, const gchar* url, gboolean generate);
static GdkPixbuf* last_fm_image_generate_pixbuf (LastFMImage* self);
LastFMImage* last_fm_image_new_with_image (GdkPixbuf* image);
LastFMImage* last_fm_image_construct_with_image (GType object_type, GdkPixbuf* image);
LastFMImage* last_fm_image_new_with_import_string (const gchar* s);
LastFMImage* last_fm_image_construct_with_import_string (GType object_type, const gchar* s);
void last_fm_image_set_size (LastFMImage* self, gint width, gint height);
const gchar* last_fm_image_get_url (LastFMImage* self);
gchar* last_fm_image_to_string (LastFMImage* self);
LastFMImage* last_fm_image_new (void);
LastFMImage* last_fm_image_construct (GType object_type);
void last_fm_image_set_url (LastFMImage* self, const gchar* value);
GdkPixbuf* last_fm_image_get_image (LastFMImage* self);
void last_fm_image_set_image (LastFMImage* self, GdkPixbuf* value);
static void last_fm_image_finalize (GObject* obj);
static void _vala_last_fm_image_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_last_fm_image_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


LastFMImage* last_fm_image_construct_basic (GType object_type) {
	LastFMImage * self = NULL;
	gint* _tmp0_ = NULL;
	self = (LastFMImage*) g_object_new (object_type, NULL);
	_g_free0 (self->priv->_url);
	self->priv->_url = NULL;
	_g_object_unref0 (self->priv->_image);
	self->priv->_image = NULL;
	_tmp0_ = g_new0 (gint, 2);
	_tmp0_[0] = last_fm_image_default_size;
	_tmp0_[1] = last_fm_image_default_size;
	self->priv->_size = (g_free (self->priv->_size), NULL);
	self->priv->_size = _tmp0_;
	self->priv->_size_length1 = 2;
	self->priv->__size_size_ = 2;
	return self;
}


LastFMImage* last_fm_image_new_basic (void) {
	return last_fm_image_construct_basic (LAST_FM_TYPE_IMAGE);
}


LastFMImage* last_fm_image_construct_with_url (GType object_type, const gchar* url, gboolean generate) {
	LastFMImage * self = NULL;
	gchar* _tmp0_;
	gint* _tmp1_ = NULL;
	g_return_val_if_fail (url != NULL, NULL);
	self = (LastFMImage*) g_object_new (object_type, NULL);
	_tmp0_ = g_strdup (url);
	_g_free0 (self->priv->_url);
	self->priv->_url = _tmp0_;
	_g_object_unref0 (self->priv->_image);
	self->priv->_image = NULL;
	_tmp1_ = g_new0 (gint, 2);
	_tmp1_[0] = last_fm_image_default_size;
	_tmp1_[1] = last_fm_image_default_size;
	self->priv->_size = (g_free (self->priv->_size), NULL);
	self->priv->_size = _tmp1_;
	self->priv->_size_length1 = 2;
	self->priv->__size_size_ = 2;
	if (generate) {
		GdkPixbuf* _tmp2_ = NULL;
		GdkPixbuf* _tmp3_;
		_tmp2_ = last_fm_image_generate_pixbuf (self);
		_tmp3_ = _tmp2_;
		_g_object_unref0 (_tmp3_);
	}
	return self;
}


LastFMImage* last_fm_image_new_with_url (const gchar* url, gboolean generate) {
	return last_fm_image_construct_with_url (LAST_FM_TYPE_IMAGE, url, generate);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


LastFMImage* last_fm_image_construct_with_image (GType object_type, GdkPixbuf* image) {
	LastFMImage * self = NULL;
	GdkPixbuf* _tmp0_;
	gint* _tmp1_ = NULL;
	g_return_val_if_fail (image != NULL, NULL);
	self = (LastFMImage*) g_object_new (object_type, NULL);
	_tmp0_ = _g_object_ref0 (image);
	_g_object_unref0 (self->priv->_image);
	self->priv->_image = _tmp0_;
	_tmp1_ = g_new0 (gint, 2);
	_tmp1_[0] = last_fm_image_default_size;
	_tmp1_[1] = last_fm_image_default_size;
	self->priv->_size = (g_free (self->priv->_size), NULL);
	self->priv->_size = _tmp1_;
	self->priv->_size_length1 = 2;
	self->priv->__size_size_ = 2;
	return self;
}


LastFMImage* last_fm_image_new_with_image (GdkPixbuf* image) {
	return last_fm_image_construct_with_image (LAST_FM_TYPE_IMAGE, image);
}


LastFMImage* last_fm_image_construct_with_import_string (GType object_type, const gchar* s) {
	LastFMImage * self = NULL;
	gchar** _tmp0_;
	gchar** _tmp1_ = NULL;
	gchar** values;
	gint values_length1;
	gint _values_size_;
	gchar* _tmp2_;
	gint* _tmp3_ = NULL;
	gint _tmp4_;
	gint _tmp5_;
	g_return_val_if_fail (s != NULL, NULL);
	self = (LastFMImage*) g_object_new (object_type, NULL);
	_tmp1_ = _tmp0_ = g_strsplit (s, "<value_seperator>", 0);
	values = _tmp1_;
	values_length1 = _vala_array_length (_tmp0_);
	_values_size_ = _vala_array_length (_tmp0_);
	_tmp2_ = g_strdup (values[0]);
	_g_free0 (self->priv->_url);
	self->priv->_url = _tmp2_;
	_g_object_unref0 (self->priv->_image);
	self->priv->_image = NULL;
	_tmp3_ = g_new0 (gint, 2);
	self->priv->_size = (g_free (self->priv->_size), NULL);
	self->priv->_size = _tmp3_;
	self->priv->_size_length1 = 2;
	self->priv->__size_size_ = 2;
	_tmp4_ = atoi (values[1]);
	self->priv->_size[0] = _tmp4_;
	_tmp5_ = atoi (values[2]);
	self->priv->_size[1] = _tmp5_;
	values = (_vala_array_free (values, values_length1, (GDestroyNotify) g_free), NULL);
	return self;
}


LastFMImage* last_fm_image_new_with_import_string (const gchar* s) {
	return last_fm_image_construct_with_import_string (LAST_FM_TYPE_IMAGE, s);
}


void last_fm_image_set_size (LastFMImage* self, gint width, gint height) {
	g_return_if_fail (self != NULL);
	self->priv->_size[0] = width;
	self->priv->_size[1] = height;
}


static GdkPixbuf* last_fm_image_generate_pixbuf (LastFMImage* self) {
	GdkPixbuf* result = NULL;
	GdkPixbuf* rv = NULL;
	gboolean _tmp0_ = FALSE;
	const gchar* _tmp1_ = NULL;
	const gchar* _tmp3_ = NULL;
	GFile* _tmp4_ = NULL;
	GFile* file;
	GFileInputStream* filestream = NULL;
	GFileInputStream* _tmp5_ = NULL;
	GFileInputStream* _tmp6_;
	GdkPixbuf* _tmp7_ = NULL;
	GdkPixbuf* _tmp8_;
	GdkPixbuf* _tmp10_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = last_fm_image_get_url (self);
	if (_tmp1_ == NULL) {
		_tmp0_ = TRUE;
	} else {
		const gchar* _tmp2_ = NULL;
		_tmp2_ = last_fm_image_get_url (self);
		_tmp0_ = g_strcmp0 (_tmp2_, "") == 0;
	}
	if (_tmp0_) {
		result = NULL;
		_g_object_unref0 (rv);
		return result;
	}
	_tmp3_ = last_fm_image_get_url (self);
	_tmp4_ = g_file_new_for_uri (_tmp3_);
	file = _tmp4_;
	_tmp5_ = g_file_read (file, NULL, &_inner_error_);
	_tmp6_ = _tmp5_;
	if (_inner_error_ != NULL) {
		goto __catch46_g_error;
	}
	_g_object_unref0 (filestream);
	filestream = _tmp6_;
	_tmp7_ = gdk_pixbuf_new_from_stream_at_scale ((GInputStream*) filestream, self->priv->_size[0], self->priv->_size[1], TRUE, NULL, &_inner_error_);
	_tmp8_ = _tmp7_;
	if (_inner_error_ != NULL) {
		goto __catch46_g_error;
	}
	_g_object_unref0 (rv);
	rv = _tmp8_;
	goto __finally46;
	__catch46_g_error:
	{
		GError * err;
		const gchar* _tmp9_ = NULL;
		err = _inner_error_;
		_inner_error_ = NULL;
		_tmp9_ = last_fm_image_get_url (self);
		fprintf (stdout, "Could not fetch album art from %s: %s\n", _tmp9_, err->message);
		_g_object_unref0 (rv);
		rv = NULL;
		_g_error_free0 (err);
	}
	__finally46:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (filestream);
		_g_object_unref0 (file);
		_g_object_unref0 (rv);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp10_ = _g_object_ref0 (rv);
	_g_object_unref0 (self->priv->_image);
	self->priv->_image = _tmp10_;
	result = rv;
	_g_object_unref0 (filestream);
	_g_object_unref0 (file);
	return result;
}


gchar* last_fm_image_to_string (LastFMImage* self) {
	gchar* result = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strconcat (self->priv->_url, "<value_seperator>", NULL);
	_tmp1_ = _tmp0_;
	_tmp2_ = g_strdup_printf ("%i", self->priv->_size[0]);
	_tmp3_ = _tmp2_;
	_tmp4_ = g_strconcat (_tmp1_, _tmp3_, NULL);
	_tmp5_ = _tmp4_;
	_tmp6_ = g_strconcat (_tmp5_, "<value_seperator>", NULL);
	_tmp7_ = _tmp6_;
	_tmp8_ = g_strdup_printf ("%i", self->priv->_size[1]);
	_tmp9_ = _tmp8_;
	_tmp10_ = g_strconcat (_tmp7_, _tmp9_, NULL);
	_tmp11_ = _tmp10_;
	_g_free0 (_tmp9_);
	_g_free0 (_tmp7_);
	_g_free0 (_tmp5_);
	_g_free0 (_tmp3_);
	_g_free0 (_tmp1_);
	result = _tmp11_;
	return result;
}


LastFMImage* last_fm_image_construct (GType object_type) {
	LastFMImage * self = NULL;
	self = (LastFMImage*) g_object_new (object_type, NULL);
	return self;
}


LastFMImage* last_fm_image_new (void) {
	return last_fm_image_construct (LAST_FM_TYPE_IMAGE);
}


const gchar* last_fm_image_get_url (LastFMImage* self) {
	const gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_url;
	return result;
}


void last_fm_image_set_url (LastFMImage* self, const gchar* value) {
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_url);
	self->priv->_url = _tmp0_;
	if (self->priv->_image == NULL) {
		GdkPixbuf* _tmp1_ = NULL;
		GdkPixbuf* _tmp2_;
		_tmp1_ = last_fm_image_generate_pixbuf (self);
		_tmp2_ = _tmp1_;
		_g_object_unref0 (_tmp2_);
	}
	g_object_notify ((GObject *) self, "url");
}


GdkPixbuf* last_fm_image_get_image (LastFMImage* self) {
	GdkPixbuf* result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, NULL);
	if (self->priv->_image == NULL) {
		_tmp0_ = self->priv->_url != NULL;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		GdkPixbuf* _tmp1_ = NULL;
		GdkPixbuf* _tmp2_;
		_tmp1_ = last_fm_image_generate_pixbuf (self);
		_tmp2_ = _tmp1_;
		_g_object_unref0 (_tmp2_);
	}
	result = self->priv->_image;
	return result;
}


void last_fm_image_set_image (LastFMImage* self, GdkPixbuf* value) {
	GdkPixbuf* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _g_object_ref0 (value);
	_g_object_unref0 (self->priv->_image);
	self->priv->_image = _tmp0_;
	g_object_notify ((GObject *) self, "image");
}


static void last_fm_image_class_init (LastFMImageClass * klass) {
	last_fm_image_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (LastFMImagePrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_last_fm_image_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_last_fm_image_set_property;
	G_OBJECT_CLASS (klass)->finalize = last_fm_image_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), LAST_FM_IMAGE_URL, g_param_spec_string ("url", "url", "url", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), LAST_FM_IMAGE_IMAGE, g_param_spec_object ("image", "image", "image", GDK_TYPE_PIXBUF, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void last_fm_image_instance_init (LastFMImage * self) {
	self->priv = LAST_FM_IMAGE_GET_PRIVATE (self);
}


static void last_fm_image_finalize (GObject* obj) {
	LastFMImage * self;
	self = LAST_FM_IMAGE (obj);
	_g_free0 (self->priv->_url);
	_g_object_unref0 (self->priv->_image);
	self->priv->_size = (g_free (self->priv->_size), NULL);
	G_OBJECT_CLASS (last_fm_image_parent_class)->finalize (obj);
}


GType last_fm_image_get_type (void) {
	static volatile gsize last_fm_image_type_id__volatile = 0;
	if (g_once_init_enter (&last_fm_image_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (LastFMImageClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) last_fm_image_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (LastFMImage), 0, (GInstanceInitFunc) last_fm_image_instance_init, NULL };
		GType last_fm_image_type_id;
		last_fm_image_type_id = g_type_register_static (G_TYPE_OBJECT, "LastFMImage", &g_define_type_info, 0);
		g_once_init_leave (&last_fm_image_type_id__volatile, last_fm_image_type_id);
	}
	return last_fm_image_type_id__volatile;
}


static void _vala_last_fm_image_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	LastFMImage * self;
	self = LAST_FM_IMAGE (object);
	switch (property_id) {
		case LAST_FM_IMAGE_URL:
		g_value_set_string (value, last_fm_image_get_url (self));
		break;
		case LAST_FM_IMAGE_IMAGE:
		g_value_set_object (value, last_fm_image_get_image (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_last_fm_image_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	LastFMImage * self;
	self = LAST_FM_IMAGE (object);
	switch (property_id) {
		case LAST_FM_IMAGE_URL:
		last_fm_image_set_url (self, g_value_get_string (value));
		break;
		case LAST_FM_IMAGE_IMAGE:
		last_fm_image_set_image (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



