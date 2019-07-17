#pragma once
#include "wx/wx.h"

class main : public wxFrame
{
public:
	main();
	~main();
/*	wxButton* m_btn1 = nullptr;
	wxTextCtrl* m_txt1 = nullptr;
	wxListBox* m_list1 = nullptr;
	*/
	int fieldh = 10; 
	int fieldw = 10;
	wxButton** btn;
	void OnButtonClicked(wxCommandEvent& evt);
	int* mine = nullptr;
	bool click = true;


	
	wxDECLARE_EVENT_TABLE();

};

