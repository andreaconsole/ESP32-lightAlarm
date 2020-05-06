// Default preferences in raw data format for PROGMEM
//
const char defprefs_txt[] PROGMEM = R"=====(
alarm_time = 17:20-70-1                              # alarm time, initial volume and bool is_alarm_active
#
clk_dst = 1                                          # Offset during daylight saving time (hours)
clk_offset = 1                                       # Offset with respect to UTC in hours
clk_server = pool.ntp.org                            # Time server to be used
#
gpio_00 = uppreset = 1
gpio_12 = upvolume = 2
gpio_13 = downvolume = 2
gpio_14 = stop
gpio_17 = resume
gpio_34 = station = icecast.omroep.nl:80/radio1-bb-mp3
#
ir_40BF = upvolume = 2
ir_C03F = downvolume = 2
#
mqqprefix = none
mqttbroker = none
mqttpasswd = *******
mqttport = 1883
mqttuser = none
#
pin_enc_clk = 25                                     # GPIO Pin number for rotary encoder "CLK"
pin_enc_dt = 26                                      # GPIO Pin number for rotary encoder "DT"
pin_enc_sw = 27                                      # GPIO Pin number for rotary encoder "SW"
pin_ir = 35                                          # GPIO Pin number for IR receiver VS1838B
pin_sd_cs = 21                                       # GPIO Pin number for SD card "CS"
pin_tft_blx = 22
pin_tft_cs = 15                                      # GPIO Pin number for TFT "CS"
pin_tft_dc = 2                                       # GPIO Pin number for TFT "DC"
pin_vs_cs = 5                                        # GPIO Pin number for VS1053 "CS"
pin_vs_dcs = 32                                      # GPIO Pin number for VS1053 "DCS"
pin_vs_dreq = 4                                      # GPIO Pin number for VS1053 "DREQ"
#
preset = 0
preset_00 = icestreaming.rai.it/2.mp3                #  0 - Radio2
preset_01 = airspectrum.cdnstream1.com:8114/1648_128 #  1 - Easy Hits Florida 128k
preset_02 = us2.internet-radio.com:8050              #  2 - CLASSIC ROCK MIAMI 256k
preset_03 = airspectrum.cdnstream1.com:8000/1261_192 #  3 - Magic Oldies Florida
preset_04 = airspectrum.cdnstream1.com:8008/1604_128 #  4 - Magic 60s Florida 60s Classic Rock
preset_05 = us1.internet-radio.com:8105              #  5 - Classic Rock Florida - SHE Radio
preset_06 = icecast.omroep.nl:80/radio1-bb-mp3       #  6 - Radio 1, NL
preset_07 = 205.164.62.15:10032                      #  7 - 1.FM - GAIA, 64k
preset_08 = antennenr-ais-edge-3008.fra-eco.cdn.addradio.net/antennenr/live/mp3/high?ar-distributor=f0b2                    #  8 - Antenne Niederrhein
preset_09 = 167.114.251.212/stream2.mp3              #  9 - Antenna1 Roma
preset_10 = 20073.live.streamtheworld.com/LOS40.mp3  # 10 - LOS 40 principales
preset_11 = icstream.rds.radio/ram                   # 11 - RAM POWER
#
toneha = 11
tonehf = 2
tonela = 11
tonelf = 15
#
volume = 70
#
wifi_00 = TISCALI_8450/*******
wifi_01 = SSID2/*******


)=====" ;
