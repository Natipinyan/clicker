#ifndef HESTORY_RESULTS_H
#define HESTORY_RESULTS_H

class ResultData
{
private:
    int ID;
    unsigned long Resulte;
    bool BetterResulte;

public:
    ResultData(int ID, unsigned long Resulte, bool BetterResulte);
    int GetID();
    unsigned long GetResulte();
    bool GetBetterResulte();

    void SetID(int ID);
    void SetResulte(unsigned long Resulte);
    void SetBetterResulte(bool BetterResulte);
};
#endif