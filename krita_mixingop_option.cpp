/*
 *  Copyright (c) 2008,2010 Lukáš Tvrdý <lukast.dev@gmail.com>
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
#include "krita_mixingop_option.h"

#include "ui_wdgmixingoptions.h"

class KritaMixingOpOptionsWidget: public QWidget, public Ui::WdgMixingOptions
{
public:
    KritaMixingOpOptionsWidget(QWidget *parent = 0)
            : QWidget(parent) {
        setupUi(this);
    }
};

KritaMixingOpOption::KritaMixingOpOption()
        : KritaPaintOpOption(i18n("Brush size"), KritaPaintOpOption::brushCategory(), false)
{
    m_checkable = false;
    m_options = new KritaMixingOpOptionsWidget();
    connect(m_options->radiusSpinBox, SIGNAL(valueChanged(int)), SIGNAL(sigSettingChanged()));
    connect(m_options->inkDepletionCHBox, SIGNAL(clicked(bool)), SIGNAL(sigSettingChanged()));
    connect(m_options->opacity, SIGNAL(clicked(bool)), SIGNAL(sigSettingChanged()));
    connect(m_options->saturation, SIGNAL(clicked(bool)), SIGNAL(sigSettingChanged()));

    setConfigurationPage(m_options);
}

KritaMixingOpOption::~KritaMixingOpOption()
{
    // delete m_options;
}

int KritaMixingOpOption::radius() const
{
    return m_options->radiusSpinBox->value();
}


void KritaMixingOpOption::setRadius(int radius) const
{
    m_options->radiusSpinBox->setValue( radius );
}



bool KritaMixingOpOption::inkDepletion() const
{
    return m_options->inkDepletionCHBox->isChecked();
}



bool KritaMixingOpOption::opacity() const
{
    return m_options->opacity->isChecked();
}


bool KritaMixingOpOption::saturation() const
{
    return m_options->saturation->isChecked();
}


void KritaMixingOpOption::writeOptionSetting(KritaPropertiesConfiguration* setting) const
{
    setting->setProperty(MIXING_RADIUS, radius());
    setting->setProperty(MIXING_INK_DEPLETION, inkDepletion());
    setting->setProperty(MIXING_USE_OPACITY, opacity());
    setting->setProperty(MIXING_USE_SATURATION, saturation());
}

void KritaMixingOpOption::readOptionSetting(const KritaPropertiesConfiguration* setting)
{
    m_options->radiusSpinBox->setValue(setting->getInt(MIXING_RADIUS));
    m_options->inkDepletionCHBox->setChecked(setting->getBool(MIXING_INK_DEPLETION));
    m_options->opacity->setChecked(setting->getBool(MIXING_USE_OPACITY));
    m_options->saturation->setChecked(setting->getBool(MIXING_USE_SATURATION));
}


