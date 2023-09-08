/*// DEVICE_NAME
    memcpy(buffer, device_name, strlen(device_name)+1);
    
    // DATETIME
    strcat(buffer, filename);

    // TENSAO
    sprintf(val_buffer, "%dV ", getVoltage());
    strcat(buffer, val_buffer);
    
    // SINAL
    sprintf(val_buffer, "%ddB ", getWifiSignal());
    strcat(buffer, val_buffer);
    
    // TEMP
    sprintf(val_buffer, "%.2f°C ", getTemp());
    strcat(buffer, val_buffer);
    
    // GIRO
    sprintf(val_buffer, "[%.2f, %.2f, %.2f] m/s ", *(getGiro()), *(getGiro()+1), *(getGiro()+2));
    strcat(buffer, val_buffer);

    // VIB
    sprintf(val_buffer, "%.2f Hz", getFreqVib());
    strcat(buffer, val_buffer);

    // CONEXAO
    sprintf(val_buffer, "%d W", getConn());
    strcat(buffer, val_buffer);
    
    // HUMID
    sprintf(val_buffer, "%dp ", getHumid());
    strcat(buffer, val_buffer);*/