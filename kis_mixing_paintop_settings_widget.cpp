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

#include "kis_mixing_paintop_settings_widget.h"

#include "kis_mixingop_option.h"
#include "kis_mixing_paintop_settings.h"

#include <kis_curve_option_widget.h>
#include <kis_pressure_opacity_option.h>

#include <kis_paintop_options_widget.h>
#include <kis_paint_action_type_option.h>
#include <kis_airbrush_option.h>

KisMixingPaintOpSettingsWidget:: KisMixingPaintOpSettingsWidget(QWidget* parent)
        : KisPaintOpOptionsWidget(parent)
{
    m_mixingOption =  new KisMixingOpOption();

    addPaintOpOption(m_mixingOption);
    addPaintOpOption(new KisCurveOptionWidget(new KisPressureOpacityOption()));
    addPaintOpOption(new KisAirbrushOption(false));
    addPaintOpOption(new KisPaintActionTypeOption());
}

KisMixingPaintOpSettingsWidget::~ KisMixingPaintOpSettingsWidget()
{
}

KisPropertiesConfiguration*  KisMixingPaintOpSettingsWidget::configuration() const
{
    KisMixingPaintOpSettings* config = new KisMixingPaintOpSettings();
    config->setOptionsWidget(const_cast<KisMixingPaintOpSettingsWidget*>(this));
    config->setProperty("paintop", "mixingbrush"); // XXX: make this a const id string
    writeConfiguration(config);
    return config;
}

void KisMixingPaintOpSettingsWidget::changePaintOpSize(qreal x, qreal y)
{
    // if the movement is more left<->right then up<->down
    if (qAbs(x) > qAbs(y)){
        m_mixingOption->setRadius( m_mixingOption->radius() + qRound(x) );
    }
}
