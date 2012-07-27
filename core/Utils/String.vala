// -*- Mode: vala; indent-tabs-mode: nil; tab-width: 4 -*-
/*
 * Copyright (c) 2012 Noise Developers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; see the file COPYING.  If not,
 * write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Authored by: Victor Eduardo <victoreduardm@gmail.com>
 */

namespace Noise.String {

    /**
     * Compares two strings. Used extensively in the views for sorting.
     * @return 1 if a > b. -1 if b > a
     */
    public inline int compare (string a, string b) {
        if (a == "" && b != "")
            return 1;

        if (a != "" && b == "")
            return -1;

        return (a > b) ? 1 : -1;
    }

    /**
     * @Deprecated: Vala's GLib integration already provides the string.escape() method.
     *              no need for an extra method.
     * Escapes the text for use with Pango Markup.
     * @return escaped text
     */
    public inline string escape (string text) {
        if (text == null || text.length < 1)
            return "";

        return Markup.escape_text (text, -1);
    }

    /**
     * @return 'true' if text consists enterely of white space.
     */
    public inline bool is_white_space (string text) {
        if (text == null)
            return true;

        return text.strip ().length == 0;
    }
}

