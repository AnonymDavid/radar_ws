Lidar logolásához fel kell iratkozni a /scan ros topicra.
Ezt manuálisan a következő paranccsal tudjuk megtenni: rostopic echo /scan
A scripts mappában található lidar_topic_log.sh script futtatásával is fel tudunk iratkozni
    és a loggoló készít egy txt fájlt a ros_logs mappába, ahová lementi a logolt lidar adatokat.
A scriptet ctrl + c gomb kombinációval tudjuk leállítani.