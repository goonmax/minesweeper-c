#include "main.h"

wxBEGIN_EVENT_TABLE(main, wxFrame)
EVT_BUTTON(1000, OnButtonClicked)
wxEND_EVENT_TABLE()


main::main() : wxFrame(nullptr, wxID_ANY, "y'all mofuckers ever fuck around and get a triple double?", wxPoint(30, 30), wxSize(800, 600))
{
	/*m_btn1 = new wxButton(this, 1000, "CLick this", wxPoint(20, 20), wxSize(150, 50));
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(20, 70), wxSize(300, 50));

	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(20, 100), wxSize(300, 300));*/

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	btn = new wxButton*[fieldw * fieldh];
	wxGridSizer *grid = new wxGridSizer(fieldw, fieldh, 0, 0);

	mine = new int[fieldw * fieldh];


	for (int x = 0; x < fieldw; x++)
	{
		for (int y = 0; y < fieldh; y++)
		{
			btn[y*fieldw + x] = new wxButton(this, 1000 + (y * fieldw + x));
			btn[y * fieldw + x] - SetFont(font);
			grid->Add(btn[y*fieldw + x], 1, wxEXPAND | wxALL);

			btn[y * fieldw + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &main::OnButtonClicked, this);
			mine[y * fieldw + x] = 0;
		}
	}
	this->SetSizer(grid); 
	grid->Layout();
}

main::~main()
{
	delete[]btn; 
}

void main::OnButtonClicked(wxCommandEvent& evt)
{
	/*m_list->AppendString(m_txt1->GetValue());*/

	int x = (evt.GetId() - 1000) % fieldw;
	int y = (evt.GetId() - 1000) / fieldw;

	if (click)
	{
		int bombs = 30;
		while (bombs)
		{
			int yy = rand() % fieldw;
			int xx = rand() % fieldh;

			if (mine[yy * fieldw + xx] == 0 && xx != x && yy != y)
			{
				mine[yy * fieldw + xx] = -1;
				bombs--;

			}



		}
		click = false;
	}

	btn[y * fieldw + x]->Enable(false);
	if (mine[y * fieldw + x] == -1)
	{
		wxMessageBox("lol you dead git gud");
		click = true;
		for (int x = 0; x < fieldw; x++)
			for (int y = 0; y < fieldh; y++)
			{
				mine[y * fieldw + x] = 0;
				btn[y * fieldw + x]->SetLabel("");
				btn[y * fieldw + x]->Enable(true); 
			}
	}
	else
	{
		int countmines = 0;
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
			{
				if (x + i >= 0 && x + i < fieldw && y + j >= 0 && y + j < fieldh)
				{
					if (mine[(y + j) * fieldw + (x + i)] == -i)
						countmines++;
				}
			}
		if (countmines > 0)
		{
			btn[y * fieldw + x]->SetLabel(std::to_string(countmines));
		}
	}
	evt.Skip(); 
}