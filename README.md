# 디지털 신호등 및 자율주행차량 간 무선통신
한국정보화진흥원 주관 2019 넷챌린지 캠프 아이디어 공모전 

은상 수상


### # 프로젝트 기간 및 참여 인원
2019.07 ~ 2019.11 / 3명


### # 개발 목적
최근 발생한 자율주행 사고는 데이터 획득에 사용되는 센서의 오작동에 의해 발생했다. 그래서 기존 자율 주행 원리 3단계에 디지털 신호등과의 무선통신 기능을 추가, 주인지 수단으로 채택하여 오류 발생률을 현저히 낮추고자 한다.


### # 개발 내용 및 범위
서버를 통해 패킷을 브로드캐스팅하는 디지털 신호등(송신 타워)을 구현하고 자율주행차량이 패킷을 수신할 수 있도록 통신 모듈을 탑재한다. 그 후 제어 서버의 신호 제어에 따라 디지털 신호등을 통해 주행을 통제하고 사고 방지를 위해 안전거리를 유지한다.


### # 사용 언어 및 라이브러리
- C, Python <br>
- LORA 모듈 통신 라이브러리 dragino_lora_app<br>
- NEO PIXEL LED 라이브러리 AdafruitNeoPixelmaster<br>
- GPS Data 수신 라이브러리 http://www.danmandle.com/blog/getting-gpsd-to-work-with-python/

### # 개발 환경
- OS : Rasibian<br>
- Tool : Arduino

### # HardWare
- 디지털 신호등 (송수신 타워)<br>
- 차량 탑재용 라즈베리파이4 (Lora 탑재)


### # Software
- 자율주행차량 패킷 수신 코드<br>
경로 : Car1 > rpi-lora-tranceiver-master > dragino_lora_app > main.c

- GPS data 수신 코드<br>
경로 : Car1 > gpsData.py

- 신호등 서버 패킷 송신 코드<br>
경로 : Server1 > rpi-lora-tranceiver-master > dragino_lora_app > main.c

- 신호등 신호 패턴 코드<br>
경로 : Digital_Traffic_Light_Signal_Pattern > LED_Pattern.ino

### # 개발 결과
KOREN SDI에서 제공하는 가상 서버를 기반으로 신호 제어 서버와 디지털 신호등(통신 타워) & 디지털 신호등 서버, 그리고 자율주행차량 간의 무선 통신을 결과로 한다. 센서를 이용한 자율주행차량의 위험 요소인 센서 인지 오류에 의한 사고를 최소화할 수 있다.

### # 기대 효과
본 프로젝트에서 제안한 아이디어로 기존 방식의 자율주행차량보다 신호 인식률을 향상시키고, 현재 신호와 잔여시간, 차량의 속도 등을 계산하여 불필요한 가/감속을 방지하여 연비를 향상 할 수 있다. 또한, 중앙 집중제어 방식을 통하여 관리운영비를 감소시키고 향후 AI, 빅데이터 등을 결합하여 교통흐름을 보다 효율적으로 제어가 가능하다.


