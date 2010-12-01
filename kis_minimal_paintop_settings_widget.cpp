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

#include "kis_minimal_paintop_settings_widget.h"

#include "kis_minimal_paintop_options.h"
#include "kis_minimal_paintop_settings.h"

#include <kis_paintop_options_widget.h>

KisMinimalPaintOpSettingsWidget:: KisMinimalPaintOpSettingsWidget(QWidget* parent)
        : KisBrushBasedPaintopOptionWidget(parent)
{
    m_minimalOption =  new KisMinimalOpOption();
    addPaintOpOption(m_minimalOption);
}

KisMinimalPaintOpSettingsWidget::~ KisMinimalPaintOpSettingsWidget()
{
}

KisPropertiesConfiguration*  KisMinimalPaintOpSettingsWidget::configuration() const
{
    KisMinimalPaintOpSettings* config = new KisMinimalPaintOpSettings();
    config->setOptionsWidget(const_cast<KisMinimalPaintOpSettingsWidget*>(this));
    config->setProperty("paintop", "minimalbrush"); // XXX: make this a const id string
    writeConfiguration(config);
    return config;
}
