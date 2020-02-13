#!/bin/bash
while read Lastname	Firstname	Login; do

if [[ $Lastname == "#" ]] ; then
    echo "ligne non prise en compte"
else
    useradd -m -d /home/"$Lastname" -c "$Lastname + $Firstname + $Login" "$Lastname"
    echo "utilisateur $Lastname ajoute "
fi
done < $1
