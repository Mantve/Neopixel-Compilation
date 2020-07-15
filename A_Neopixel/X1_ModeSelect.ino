void ModeSelect()
{
    bool readingUP = digitalRead(UP_Pin);
    if (readingUP != lastButtonStateUP)
    {
        lastDebounceTimeUP = millis();
    }

    if ((millis() - lastDebounceTimeUP) > debounceDelayUP)
    {
        if (readingUP != buttonStateUP)
        {
            buttonStateUP = readingUP;
            if (buttonStateUP == HIGH)
            {
                showType++;
                if (showType > 15)
                    showType = 0;
                EEPROM.write(ShowAdress, showType);
                lastButtonStateUP = readingUP;
                StopIt = true;
                setAll(0, 0, 0);
                showStrip();
                return;
            }
        }
    }
    lastButtonStateUP = readingUP;


    bool readingDOWN = digitalRead(DOWN_Pin);
    if (readingDOWN != lastButtonStateDOWN)
    {
        lastDebounceTimeDOWN = millis();
    }

    if ((millis() - lastDebounceTimeDOWN) > debounceDelayDOWN)
    {
        if (readingDOWN != buttonStateDOWN)
        {
            buttonStateDOWN = readingDOWN;
            if (buttonStateDOWN == HIGH)
            {

                showType--;
                if (showType < 0)
                    showType = 15;
                EEPROM.write(ShowAdress, showType);
                lastButtonStateUP = readingUP;
                StopIt = true;
                setAll(0, 0, 0);
                showStrip();
                return;
            }
        }
    }
    lastButtonStateDOWN = readingDOWN;
}
