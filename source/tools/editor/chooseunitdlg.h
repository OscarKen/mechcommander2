/*************************************************************************************************\
ChooseUnitDlg.h		: Interface for the ChooseUnitDlg component.
//---------------------------------------------------------------------------//
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
//===========================================================================//
\*************************************************************************************************/

#pragma once

#ifndef CHOOSEUNITDLG_H
#define CHOOSEUNITDLG_H

//#include <elist.h>
//#include "objective.h"
//#include "editorobjectmgr.h"


class ChooseUnitDlg: public CDialog
{
public:
	typedef Unit *unit_ptr_type;

	ChooseUnitDlg( unit_ptr_type &unitPtr, int32_t alignmentToExclude = -1 );

	BOOL OnCommand(WPARAM wParam, LPARAM lParam); // called by child controls to inform of an event
	void OnUsePointer();
	void OnCancel();
	void OnOK();

	virtual ~ChooseUnitDlg();

	BOOL OnInitDialog();

private:
	typedef CDialog inherited;

	// suppressing these
	inline ChooseUnitDlg();
	ChooseUnitDlg& operator=( const ChooseUnitDlg& lgUnitPtr );

	int32_t m_alignmentToExclude;
	unit_ptr_type *m_pModifiedUnitPtr;
	unit_ptr_type *m_pUnitPtr;
	CComboBox *m_pComboBox;
	EditorObjectMgr::UNIT_LIST m_unitList;
	CButton *m_pUsingPointerButton;
	CButton *m_pCancelButton;
	CButton *m_pOKButton;
};


//*************************************************************************************************
#endif  // end of file ( ChooseUnitDlg.h )
