void Style(char HTML[])
{
  strcat(HTML, "<style>");
  strcat(HTML, "h2{");
  strcat(HTML, "text-align: center;");
  strcat(HTML, "}");
  strcat(HTML, "table {");
  strcat(HTML, " font-family: arial, sans-serif;");
  strcat(HTML, "border-collapse: collapse;");
  strcat(HTML, "width: 100%;");
  strcat(HTML, "}");
  strcat(HTML, "td, th {");
  strcat(HTML, "border: 1px solid #dddddd;");
  strcat(HTML, "text-align: left;");
  strcat(HTML, "padding: 8px;");
  strcat(HTML, "}");
  strcat(HTML, "tr:nth-child(even) {");
  strcat(HTML, "background-color: #dddddd;");
  strcat(HTML, "}");
  strcat(HTML, "</style>");
}