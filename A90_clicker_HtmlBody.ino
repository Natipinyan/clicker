void Body(char HTML[])
{
  strcat(HTML, "<table>");
  strcat(HTML, "<tr>");
  strcat(HTML, "<th>Press id</th>");
  strcat(HTML, "<th>Press Resulte</th>");
  strcat(HTML, "<th>Broke A Record</th>");
  strcat(HTML, "</tr>");
  Algorithmics(HTML);
  strcat(HTML, "</table>");
  strcat(HTML, "</body>");
  strcat(HTML, "</html>");
}
