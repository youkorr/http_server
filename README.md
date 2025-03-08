# HTTP Server pour ESPHome

Ce composant externe permet à un ESP32-S3 Box 3 sous ESPHome d'héberger un serveur HTTP minimal sur le **port 8080** afin de servir des fichiers depuis la carte SD.  
Cela permet de contourner la limitation d'ESPHome qui ne peut lire des fichiers audio qu'à partir d'une URL.

## 📌 Fonctionnalités
✅ Héberge un **serveur HTTP léger** sur l'ESP32  
✅ Sert des fichiers stockés sur **la carte SD**  
✅ Compatible avec le lecteur **`media_player`** d'ESPHome  
✅ Permet de **lire des fichiers audio localement** en contournant la restriction des URLs  

## 🚀 Installation
1. **Copie du composant**  
   Place le dossier `http_server` dans `config/esphome/custom_components/`.  
   La structure doit être la suivante :

external_components:
  - source: github://youkorr/sd_card.git  # Ton composant SD
  - source: local
    components: [http_server]

esphome:
  name: esp32_audio

wifi:
  ssid: "TonWiFi"
  password: "TonMotDePasse"

media_player:
  - platform: i2s_audio
    id: player
    name: "Audio Player"
    dac_type: external

script:
  - id: play_audio
    then:
      - media_player.play_media:
          id: player
          media_url: "http://<ip_esp>:8080/test.flac"
          media_type: "music"

http://<ip_de_ton_esp>:8080/test.flac

---

### **📌 Explication**
✅ **Documente l'installation et l'utilisation du serveur HTTP**  
✅ **Explique comment l'ajouter à ESPHome**  
✅ **Ajoute un guide de dépannage**  

🚀 **Ajoute ce fichier et dis-moi si tout fonctionne bien !** 😊
