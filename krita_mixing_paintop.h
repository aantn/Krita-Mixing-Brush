/*
 *  Copyright (c) 2008 Boudewijn Rempt <boud@valdyas.org>
 *  Copyright (c) 2008, 2009 Lukáš Tvrdý <lukast.dev@gmail.com>
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

#ifndef KRITA_MIXING_PAINTOP_H_
#define KRITA_MIXING_PAINTOP_H_

#include <krita_paintop.h>
#include <krita_types.h>

#include "mixing_brush.h"
#include "krita_mixing_paintop_settings.h"

class KritaPainter;

class KritaMixingPaintOp : public KritaPaintOp
{

public:

    KritaMixingPaintOp(const KritaMixingPaintOpSettings *settings, KritaPainter * painter, KritaImageWSP image);
    virtual ~KritaMixingPaintOp();

    qreal paintAt(const KritaPaintInformation& info);

private:
    KritaPaintDeviceSP m_dab;
    MixingBrush * m_mixingBrush;
    KritaPressureOpacityOption m_opacityOption;
    MixingProperties m_properties;
};

#endif // KRITA_MIXING_PAINTOP_H_
