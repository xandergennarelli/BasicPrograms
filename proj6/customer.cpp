else{
  opfile.open("ocustomer.txt");
  choice = "yes";

  if (fileRead){
    readCustomer(pfile, cNameList[index], cAgeList[index], cSRList[index]);
    if (!pfile){
      choice = "no";
    }
  }

  while (choice != "no" && index < PLIST_SIZE){
    if (!fileRead){
      requestInfo(cout, "Please enter your name followed by your age then shipping rate");
      readCustomer(cin, cNameList[index], cAgeList[index], cSRList[index]);
    }

    writeCustomer(opfile, cNameList[index], cAgeList[index], cSRList[index]);

    index++;
    if (!fileRead){
      choice = readAgain(cout, cin);
    }
    else{
      readCustomer(pfile, cNameList[index], cAgeList[index], cSRList[index]);
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

  if ((index = findPerson(cNameList, choice)) != -1){
    cout << "Found your person: " << endl;
    writeCustomer(cout, cNameList[index], cAgeList[index], cSRList[index]);
  }
  else{
    cout << "Couldn't find your person: " << choice << endl;
  }
}
