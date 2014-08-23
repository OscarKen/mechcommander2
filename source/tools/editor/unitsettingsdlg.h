//===========================================================================//
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
//===========================================================================//

#pragma once

#if !defined(AFX_UNITSETTINGSDLG_H__66842972_D1C0_48E8_8DF6_930ED43A3896__INCLUDED_)
#define AFX_UNITSETTINGSDLG_H__66842972_D1C0_48E8_8DF6_930ED43A3896__INCLUDED_

/////////////////////////////////////////////////////////////////////////////
// UnitSettingsDlg dialog

//#include <elist.h>
//#include "action.h"

class Unit;

class UnitSettingsDlg : public CDialog
{
public:
	UnitSettingsDlg(EList<Unit*, Unit*>&, ActionUndoMgr &undoMgr);   // standard constructor

	//{{AFX_DATA(UnitSettingsDlg)
	enum { IDD = IDD_UNITSETTINGS };
	CComboBox	m_Variant;
	CComboBox	m_Pilot;
	CComboBox	m_Mech;
	CComboBox	m_Group;
	int32_t		m_Alignment;
	CString	m_SquadEdit;
	int32_t		m_SelfRepairBehavior;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(UnitSettingsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	void DoColorBox( CWnd* pWnd );

	//{{AFX_MSG(UnitSettingsDlg)
	afx_msg void OnSelchangeGroup();
	afx_msg void OnHighilight2edit();
	afx_msg void OnChangeHighlight1();
	afx_msg void OnHighlight1edit();
	afx_msg void OnChangeHighlight2();
	afx_msg void OnChangeBase();
	afx_msg void OnBaseedit();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, uint32_t nCtlColor);
	afx_msg void OnSelchangeMech();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	afx_msg void OnAlign1(uint32_t which);

	void applyChanges();
	ModifyBuildingAction *pAction;

	typedef EList< Unit*, Unit* > UNIT_LIST;
	UNIT_LIST& units;

	CBrush		baseBrush;
	CBrush		brush1;
	CBrush		brush2;

	void updatePossibiltyControls();
	Unit *pFirstPossibility;
	int32_t getPossibilityIndex();
	void updateMemberVariables();
	ActionUndoMgr *pUndoMgr;
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_UNITSETTINGSDLG_H__66842972_D1C0_48E8_8DF6_930ED43A3896__INCLUDED_)
