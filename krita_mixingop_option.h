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
#ifndef KRITA_MIXINGOP_OPTION_H
#define KRITA_MIXINGOP_OPTION_H

#include <krita_paintop_option.h>
#include <krita_export.h>

const QString MIXING_RADIUS = "Mixing/radius";
const QString MIXING_INK_DEPLETION = "Mixing/inkDepletion";
const QString MIXING_USE_OPACITY = "Mixing/opacity";
const QString MIXING_USE_SATURATION = "Mixing/saturation";

class KritaMixingOpOptionsWidget;

class KritaMixingOpOption : public KritaPaintOpOption
{
public:
    KritaMixingOpOption();
    ~KritaMixingOpOption();

    void setRadius(int radius) const;
    int radius() const;

    bool inkDepletion() const; 
    bool saturation() const;
    bool opacity() const;
    
    void writeOptionSetting(KritaPropertiesConfiguration* setting) const;
    void readOptionSetting(const KritaPropertiesConfiguration* setting);


private:

    KritaMixingOpOptionsWidget * m_options;

};

class MixingProperties{
public:
    int radius;
    bool inkDepletion;
    bool useOpacity;
    bool useSaturation;
    
    void readOptionSetting(const KritaPropertiesConfiguration* settings){
            radius = settings->getInt(MIXING_RADIUS);
            inkDepletion = settings->getBool(MIXING_INK_DEPLETION);
            useOpacity = settings->getBool(MIXING_USE_OPACITY);
            useSaturation = settings->getBool(MIXING_USE_SATURATION);
    }
};

#endif
