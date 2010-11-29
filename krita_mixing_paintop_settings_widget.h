/*
 *  Copyright (c) 2008 Lukas Tvrdy <lukast.dev@gmail.com>
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

#ifndef KRITA_MIXINGPAINTOP_SETTINGS_WIDGET_H_
#define KRITA_MIXINGPAINTOP_SETTINGS_WIDGET_H_

#include <krita_paintop_options_widget.h>

#include "ui_wdgmixingoptions.h"

class KritaPaintActionTypeOption;
class KritaMixingOpOption;
class KritaPressureOpacityOption;

class KritaMixingPaintOpSettingsWidget : public KritaPaintOpOptionsWidget
{
    Q_OBJECT

public:
    KritaMixingPaintOpSettingsWidget(QWidget* parent = 0);
    virtual ~KritaMixingPaintOpSettingsWidget();

    KritaPropertiesConfiguration* configuration() const;
    
    ///Reimplemented
    void changePaintOpSize(qreal x, qreal y);

public:
    KritaMixingOpOption* m_mixingOption;
};

#endif
