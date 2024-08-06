void Head(char HTML[])
{
    strcat(HTML, "<!DOCTYPE html>");
    strcat(HTML, "<html lang=\"en\">");
    strcat(HTML, "<head>");
    strcat(HTML, "<meta charset=\"UTF-8\">");
    strcat(HTML, "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
    strcat(HTML, "<title>Document</title>");
    Style(HTML);
    strcat(HTML, "</head>");
}