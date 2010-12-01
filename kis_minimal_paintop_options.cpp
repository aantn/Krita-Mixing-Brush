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
#include "kis_minimal_paintop_options.h"

#include "ui_wdgminimaloptions.h"

class KisMinimalOpOptionsWidget: public QWidget, public Ui::WdgMinimalOptions
{
public:
    KisMinimalOpOptionsWidget(QWidget *parent = 0)
            : QWidget(parent) {
        setupUi(this);
    }
};

KisMinimalOpOption::KisMinimalOpOption()
        : KisPaintOpOption(i18n("Brush size"), KisPaintOpOption::brushCategory(), false)
{
    m_checkable = false;
    m_options = new KisMinimalOpOptionsWidget();
    connect(m_options->exampleWidget, SIGNAL(valueChanged(int)), SIGNAL(sigSettingChanged()));

    setConfigurationPage(m_options);
}

KisMinimalOpOption::~KisMinimalOpOption()
{
    // delete m_options;
}

int KisMinimalOpOption::exampleSetting() const
{
    return m_options->exampleWidget->value();
}


void KisMinimalOpOption::setExampleSetting(int exampleSetting) const
{
    m_options->exampleWidget->setValue( exampleSetting );
}


void KisMinimalOpOption::writeOptionSetting(KisPropertiesConfiguration* setting) const
{
    setting->setProperty(EXAMPLE_SETTING, exampleSetting());
}

void KisMinimalOpOption::readOptionSetting(const KisPropertiesConfiguration* setting)
{
    m_options->exampleWidget->setValue(setting->getInt(EXAMPLE_SETTING));
}


