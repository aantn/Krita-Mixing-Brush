/*
 *  Copyright (c) 2008 Lukáš Tvrdý <lukast.dev@gmail.com>
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

#include "krita_mixing_paintop_settings.h"

#include <krita_mixingop_option.h>

#include <krita_paint_action_type_option.h>
#include <krita_airbrush_option.h>

KritaMixingPaintOpSettings::KritaMixingPaintOpSettings()
{
}

bool KritaMixingPaintOpSettings::paintIncremental()
{
    return (enumPaintActionType)getInt("PaintOpAction", WASH) == BUILDUP;
}

bool KritaMixingPaintOpSettings::isAirbrushing() const
{
    return getBool(AIRBRUSH_ENABLED);
}

int KritaMixingPaintOpSettings::rate() const
{
    return getInt(AIRBRUSH_RATE);
}

QPainterPath KritaMixingPaintOpSettings::brushOutline(const QPointF& pos, KritaPaintOpSettings::OutlineMode mode, qreal scale, qreal rotation) const
{
    Q_UNUSED(scale);
    Q_UNUSED(rotation);
    QPainterPath path;
    if (mode == CursorIsOutline){
        qreal size = getInt(MIXING_RADIUS) * 2 + 1;
        QRectF rc(0, 0, size, size);
        rc.translate(-rc.center());
        path.addEllipse(rc);
        path.translate(pos);
    }
    return path;
}

#if defined(HAVE_OPENGL)
QString KritaMixingPaintOpSettings::modelName() const
{
    return "3d-pencil";
}
#endif

