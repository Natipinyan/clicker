void Algorithmics(char HTML[])
{
    int tmpCnt = cntHistory;
    char timeToString[10];
    do
    {
        if (resultsHistory[tmpCnt]->GetResulte() != -1)
        {
            strcat(HTML, "<tr>");
            strcat(HTML, "<td>");
            itoa(resultsHistory[tmpCnt]->GetResulte(), timeToString, 10);
            strcat(HTML, timeToString);
            strcat(HTML, "</td>");
            strcat(HTML, "<td>");
            if (resultsHistory[tmpCnt]->GetBetterResulte())
                strcat(HTML, "true");
            else
                strcat(HTML, "false");
            strcat(HTML, "</td>");
            strcat(HTML, "</tr>");
        }
        tmpCnt = (tmpCnt == 0) ? 10 : tmpCnt;
        tmpCnt--;
    } while (tmpCnt != cntHistory);
}
