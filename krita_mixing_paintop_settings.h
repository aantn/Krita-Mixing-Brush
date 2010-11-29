/*
 *  Copyright (c) 2008,2009 Lukáš Tvrdý <lukast.dev@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KRITA_MIXING_PAINTOP_SETTINGS_H_
#define KRITA_MIXING_PAINTOP_SETTINGS_H_

#include <krita_paintop_settings.h>
#include <krita_types.h>

#include "krita_mixing_paintop_settings_widget.h"

#include <krita_pressure_opacity_option.h>

#include <opengl/krita_opengl.h>

#if defined(_WIN32) || defined(_WIN64)
# include <windows.h>
#endif

class QWidget;
class QString;

class QDomElement;
class QDomDocument;


class KritaMixingPaintOpSettings : public KritaPaintOpSettings
{

public:
    KritaMixingPaintOpSettings();
    virtual ~KritaMixingPaintOpSettings() {}

    virtual QPainterPath brushOutline(const QPointF& pos, OutlineMode mode, qreal scale = 1.0, qreal rotation = 0.0) const;

    bool paintIncremental();
    bool isAirbrushing() const;
    int rate() const;
    
#if defined(HAVE_OPENGL)
    QString modelName() const;
#endif

};

#endif
