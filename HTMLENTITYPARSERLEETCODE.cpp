/*

HTML entity parser is the parser that takes HTML code as input and replace all the entities of the special characters by the characters itself.

The special characters and their entities for HTML are:

Quotation Mark: the entity is &quot; and symbol character is ".
Single Quote Mark: the entity is &apos; and symbol character is '.
Ampersand: the entity is &amp; and symbol character is &.
Greater Than Sign: the entity is &gt; and symbol character is >.
Less Than Sign: the entity is &lt; and symbol character is <.
Slash: the entity is &frasl; and symbol character is /.
Given the input text string to the HTML parser, you have to implement the entity parser.

Return the text after replacing the entities by the special characters.




*/








class Solution {
public:
    string entityParser(string text) {
       string res;
        for(int i = 0;i<text.size();i++){
            if(text[i]=='&'&&text[i+1]=='q'&&text[i+2]=='u'&&text[i+3]=='o'&&text[i+4]=='t'&&text[i+5]==';'){
                res+='\"';
                i+=5;
            }
            else if(text[i]=='&'&&text[i+1]=='a'&&text[i+2]=='p'&&text[i+3]=='o'&&text[i+4]=='s'&&text[i+5]==';'){
                res+='\'';
                i+=5;
            }
            else if(text[i]=='&'&&text[i+1]=='a'&&text[i+2]=='m'&&text[i+3]=='p'&&text[i+4]==';'){
                res+='&';
                i+=4;
            }
            else if(text[i]=='&'&&text[i+1]=='g'&&text[i+2]=='t'&&text[i+3]==';'){
                res+='>';
                i+=3;
            }
            else if(text[i]=='&'&&text[i+1]=='l'&&text[i+2]=='t'&&text[i+3]==';'){
                res+='<';
                i+=3;
            }
            else if(text[i]=='&'&&text[i+1]=='f'&&text[i+2]=='r'&&text[i+3]=='a'&&text[i+4]=='s'&&text[i+5]=='l'&&text[i+6]==';'){
                res+='/';
                i+=6;
            }
            else
                res+=text[i];
        }
        return res;        
    }
};