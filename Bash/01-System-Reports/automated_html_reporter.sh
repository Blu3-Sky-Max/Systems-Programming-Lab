#!/bin/bash 
# Author : Blu3 sky 
#program to output a system information page 
TITLE="System Information Report For $HOSTNAME"
Curent="$(date +"%x %r %z")"
TIMESTAMP="Generated $Curent,by $USER"
report_uptime (){
 cat << _EOF_
	<h2>"uptime"</h2>
	<pre>$(uptime)</pre>

_EOF_
}



report_disk_space (){
	cat << _EOF_
	<h2> "disk space utilization" </h2>
	<pre>$(df)</pre>
_EOF_
}
report_home_space(){
	cat << _EOF_
	<h2>"home space" </h2>
	<pre>$(du)</pre>

_EOF_
}
cat << _EOF_
  <html>
   	<header> 
            <title>$TITLE</title> 
     </header> 
    <body> 
    <h1> $TITLE</h1>
     <p>$TIMESTAMP</P>        
	$(report_uptime)
	$(report_disk_space)
	$(report_home_space)
    </body> 
   </html> 
_EOF_
