//STATI: EROGAZIONE, ATTESA, CERCA_ATTENZIONI, PETTING


//STATE MACHINE


while(true){
	
	//STATE UPDATE
	borracciaPresente = rilevaBorraccia();
	
	if(borracciaPresente == true && giàRiempita == false){  //giàRiempita evita che la borraccia venga ririempita se viene lasciata dentro per molto tempo
		STATO = EROGAZIONE;  
	}
	else{
		if(borracciaPresente == false) giàRiempita = false;  //quando viene tolta la borraccia possiamo resettare giàRiempita e abilitiamo un nuovo riempimento
		
		if(((STATO == ATTESA) || (STATO == CERCA_ATTENZIONI)) && carezze() == true) STATO = PETTING;
		else if((STATO == ATTESA) && (timerSolitudine > istanteSolitudine) && carezze() == false && personePresenti == true) STATO = CERCA_ATTENZIONI;
		
	}
	
	//alla fine di ogni stato si va in attesa come vedrai nelle prossime funzioni erogazione(), richiamaAttenzione(), reagisciCarezze()...
	
	
	//STATE ACTION
	if(STATO == EROGAZIONE) erogazione();
	else if(STATO == CERCA_ATTENZIONI) richiamaAttenzione();
	else if(STATO == PETTING) reagisciCarezze();
	else if(STATO == ATTESA){
		
		int scegliAnimazione = rand(10);
		
		if(scegliAnimazione == 0) animazioneTriste(); //animazione SONO SPLASHY E SONO TRISTEE NESSUNO MI CONSIDERA
		else if(scegliAnimazione == 1) animazioneFelice(); //animazione VA CHE BELLA GIORNATA!!
		else if(scegliAnimazione >= 2) //non succede nulla
		
		personePresenti = controllaPersone();
	} 
	
}


bool rilevaBorraccia(){
	//sensore sonar HIGH o LOW 
}



//------------------------------------------------------------------------------------------------------------
//erogazione()
void erogazione(){
	litriErogati = 0; //inizializza litri erogati
	litriDaRiempire = leggiPotenziometro(); //leggi quanto erogare
	attivaPompa();  //pinRelayPompa = HIGH;
	
	while((litriErogati + safetyTrashold) < litriDaRiempire && borracciaPresente() == true){  //continui ad aggiornare fin tanto che non hai raggiunto la quota e che la borraccia è presente
		litriErogati = aggiornaFlusso(litriErogati); //aggiorna quanto è stato erogato
	}
	
	disattivaPompa();  //pinRelayPompa = LOW;
	
	giàRiempita = true; 
	
	STATO = ATTESA;
	timerSolitudine = 0;
}



int aggiornaFlusso(){ //o float o altro? (dipende se millilitri o litri, meglio mL secondo me)

	//ogni secondo (o mezzo secondo o meno) leggi numero di impulsi del flussometro (f) dalla scheda counter
	flussoCorrente = f;
	//resetta il conteggio di impulsi sulla scheda counter
	f=0;
	//aggiorna i litri erogati
	litriErogati += Q/60  //usa la formula Q=f/73 (guarda video youtube)
   	//Q è in litri/minuto, quindi Q/60 è litri/secondo
}


//------------------------------------------------------------------------------------------------------------
//richiamaAttenzione()
void richiamaAttenzione(){
	animazioneAttenzione(); //animazione HEEEYYY SONO QUAAA BRUTTI PEZZI DI MERDA VENITE A BEREEE
	STATO = ATTESA;
	timerSolitudine = 0;
}

//------------------------------------------------------------------------------------------------------------
//reagisciCarezze()
void reagisciCarezze(){
	animazioneCarezze(); //animazione QUESTE CAREZZE SONO BELLE PROPRIO!
	STATO = ATTESA;
	timerSolitudine = 0;
}


//----------------------------------------------------------------------------------------
//controllaPersone()
bool controllaPersone(){
	//sensore di movimento che rileva persone che passano
}
