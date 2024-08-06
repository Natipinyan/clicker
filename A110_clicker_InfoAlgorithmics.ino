void Algorithmics(char HTML[])
{
  int tmpCnt = (cntHistory == 0) ? 9 : cntHistory - 1;
  char timeToString[10];
  int start = tmpCnt;
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

    tmpCnt--;
    if (tmpCnt < 0)
      tmpCnt = 9;
  } while (tmpCnt != start);
}
