/***************************************************************************
 *   Copyright (c) 2004 Jürgen Riegel <juergen.riegel@web.de>              *
 *   Copyright (c) 2012 Luke Parry <l.parry@warwick.ac.uk>                 *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#ifndef DRAWINGGUI_VIEWPROVIDERDIMENSION_H
#define DRAWINGGUI_VIEWPROVIDERDIMENSION_H

#include <App/PropertyUnits.h>

#include "ViewProviderDrawingView.h"
#include <Mod/TechDraw/App/DrawViewDimension.h>


namespace TechDrawGui {


class TechDrawGuiExport ViewProviderDimension : public ViewProviderDrawingView
{
    PROPERTY_HEADER(TechDrawGui::ViewProviderDimension);

public:
    /// constructor
    ViewProviderDimension();
    /// destructor
    virtual ~ViewProviderDimension();

    App::PropertyFont     Font;
    App::PropertyLength   Fontsize;
    App::PropertyFloat    LineWidth;
    App::PropertyColor    Color;
    App::PropertyBool     FlipArrowheads;
    App::PropertyBool     TiltText;
    App::PropertyBool     ExtendToCenter;

    virtual void attach(App::DocumentObject *);
    virtual void setDisplayMode(const char* ModeName);
    virtual bool useNewSelectionModel(void) const {return false;}
    /// returns a list of all possible modes
    virtual std::vector<std::string> getDisplayModes(void) const;
    virtual void updateData(const App::Property*);
    virtual void onChanged(const App::Property* p);

    virtual TechDraw::DrawViewDimension* getViewObject() const;
};

} // namespace TechDrawGui


#endif // DRAWINGGUI_VIEWPROVIDERDIMENSION_H
