{
  open Parseur     
  exception Eof
  exception TokenInconu
}
rule token = parse
            [' ' '\t']           { token lexbuf } 
          | ['\n' ]              { EOL }
          | ['0'-'9']+  	     { NOMBRE }
	   | ['0'-'9']+'.'['0'-'9']+ { FLOTTANT }
          | '+'                  { PLUS }
          | '-'                  { MOINS }
          | '*'                  { FOIS }
          | '/'                  { DIV }
          | '%'                  { MODULO }
          | '('                  { GPAREN }
          | ')'                  { DPAREN }
          | eof                  { raise Eof }
	   | _                    { raise TokenInconu }



