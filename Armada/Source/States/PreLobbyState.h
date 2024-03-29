/*
Author:			Daniel Habig
Date:			11-15-13
File:			IntroState.h
Purpose:		gamestate that allows selection of sub-states
*/
#pragma once
#include "igamestate.h"
#include "../Graphics/Graphics.h"
#include "../Graphics/Button.h"
#include "../Network/Client.h"
#include "../State_Machine/Server_Machine.h"
#include "LobbyState.h"
#include "SetupState.h"

class CPreLobbyState : public IGameState
{
private:
	enum EPreLobbyButtons { HOST, JOIN_LAN, JOIN_WAN, BACK, NUM_BUTTONS };

private:		//Data
	CStarField*		m_pStarField;
	GUI::CButton	m_vButtons[NUM_BUTTONS];
	CLobbyState		m_cLobbyState;
	CSetupState		m_cSetupState;

	//Network
	CServerMachine		m_cSMach;
	Network::CClient	m_cClient;


protected:		//Data
public:			//Data

private:		//Methods
	void		UpdateClient(Time dDelta);
protected:		//Methods
public:			//Methods
							CPreLobbyState	( void );						// ctor
	virtual					~CPreLobbyState	( void );						// dtor

	// IGameState Interface					  
	/*virtual*/ void		Enter		( Sprite::CSprite* pSprite, Input::CInput* pInput, Text::CText* pText, Audio::CAudio* pAudio  );	// load resources
	/*virtual*/ void		Exit		( void );																							// unload resources

	// Primary Funcs						  
	/*virtual*/ void		Input		( void );							// handle user input
	/*virtual*/ void		Update		( Time delta, Time gameTime );		// update game entities
	/*virtual*/ void		Render		( void );							// render game entities

	inline void SetStarField(CStarField* pStarField) { this->m_pStarField = pStarField; }
};


