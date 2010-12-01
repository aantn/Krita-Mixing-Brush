/*
 *  Copyright (c) YEAR YOUR_NAME <YOUR_EMAIL>
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

#ifndef KIS_MINIMAL_PAINTOP_H_
#define KIS_MINIMAL_PAINTOP_H_

#include <kis_paintop.h>
#include <kis_brush_based_paintop.h>
#include <kis_types.h>

#include "kis_minimal_paintop_settings.h"

class KisPainter;

class KisMinimalPaintOp : public KisBrushBasedPaintOp
{

public:

    KisMinimalPaintOp(const KisMinimalPaintOpSettings *settings, KisPainter * painter, KisImageWSP image);
    virtual ~KisMinimalPaintOp();

    qreal paintAt(const KisPaintInformation& info);

private:
};

#endif // KIS_MINIMAL_PAINTOP_H_
