/***************************************************************
 * Name:      terApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Karol Szykula (karol.szykula@gmail.com)
 * Created:   2017-11-30
 * Copyright: Karol Szykula ()
 * License:
 **************************************************************/

#include "terApp.h"
#include "TerSerUI.h"


//(*AppHeaders
#include <wx/image.h>
//*)

IMPLEMENT_APP(terApp);

bool terApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	TerSerUI* Frame = new TerSerUI(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
