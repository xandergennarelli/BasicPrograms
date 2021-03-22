if (pTypeChoice == "person"){
  opfile.open("operson.txt");
}
else{
  opfile.open("ocustomer.txt");
}
choice = "yes";

if (fileRead){
  readPerson(pfile, pTypeChoice, nameList[index], ageList[index], srList[index]);
  if (!pfile){
    choice = "no";
  }
}

while (choice != "no" && index < PLIST_SIZE){
  if (!fileRead){
    requestInfo(cout, pTypeChoice);
    readPerson(cin, pTypeChoice, nameList[index], ageList[index], srList[index]);
  }

  writePerson(opfile, pTypeChoice, nameList[index], ageList[index], srList[index]);

  index++;
  if (!fileRead){
    choice = readAgain(cout, cin);
  }
  else{
    readPerson(pfile, pTypeChoice, nameList[index], ageList[index], srList[index]);
    if (!pfile){
      choice = "no";
    }
  }
}

if (fileRead){
  pfile.close();
}
opfile.close();

cout << "Which person are you looking for? " << endl;
getline(cin, choice);

if ((index = findPerson(nameList, choice)) != -1){
  cout << "Found your person: " << endl;
  writePerson(cout, pTypeChoice, nameList[index], ageList[index], srList[index]);
}
else{
  cout << "Couldn't find your person: " << choice << endl;
}
