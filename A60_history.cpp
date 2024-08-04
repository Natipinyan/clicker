#include "A50_history.h"

ResultData::ResultData(int ID, unsigned long Resulte, bool BetterResulte)
{
    this->ID = ID;
    this->BetterResulte = BetterResulte;
    this->Resulte = Resulte;
}
int ResultData::GetID() { return ID; }
unsigned long ResultData::GetResulte() { return Resulte; }
bool ResultData::GetBetterResulte() { return BetterResulte; }

void ResultData::SetID(int ID) { this->ID = ID; }
void ResultData::SetResulte(unsigned long Resulte) { this->Resulte = Resulte; }
void ResultData::SetBetterResulte(bool BetterResulte) { this->BetterResulte = BetterResulte; }