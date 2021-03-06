#include "RewardCommand.h"

RewardCommand::RewardCommand() :
		Command() {
}

int ExplorationApprove(Annabell *annabell, Monitor *Mon);
string Reward(Annabell *annabell, Monitor *Mon, int partial_flag, int n_iter);

int RewardCommand::doExecute() {
	if (input_token.size() > 2) {
		Display->Warning("syntax error.");
		return 1;
	}
	int n_iter;
	if (input_token.size() == 1) {
		n_iter = annabell->ElActfSt->K;
	}
	else {
		stringstream ss1(input_token[1]);
		ss1 >> n_iter;
		if (!ss1) {
			Display->Warning("Cannot convert token to integer.");
		}
	}
	if (annabell->flags->CompleteOutputFlag == true) {
		annabell->flags->OutPhrase = "";
	}
	//int ex_ph = ExplorationPhaseIdx;
	string out_phrase = Reward(annabell, Mon, 0, n_iter);
	if (annabell->flags->OutPhrase != "" && out_phrase != "") {
		annabell->flags->OutPhrase = annabell->flags->OutPhrase + " " + out_phrase;
	} else {
		annabell->flags->OutPhrase = annabell->flags->OutPhrase + out_phrase;
	}

	annabell->flags->CompleteOutputFlag = true;
	//ExplorationPhaseIdx=ex_ph;
	//ExplorationPhaseIdx=0;
	//annabell->EPhaseI->Clear();

	// added 5/01/2013
	annabell->SetAct(START_ST_A, NULL_ACT, NULL_ACT);
	annabell->StActRwdUpdate();
	Mon->Print();
	annabell->Update();
	ExecuteAct(annabell, Mon, STORE_ST_A, NULL_ACT, NULL_ACT);
	ExplorationApprove(annabell, Mon);
	annabell->flags->ExplorationPhaseIdx = 0;
	annabell->flags->AnswerTimeUpdate = true;
	// check if the output is a sensorymotor command
	CheckSensoryMotor(annabell->flags->OutPhrase, annabell, Display);

	return 0;

}
