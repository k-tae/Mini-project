# 🚗 스마트 차량 공조 시스템 (Mini-project)

## 📋 프로젝트 소개
본 프로젝트는 차량 내부 환경(온도, 습도 등)을 자동으로 제어하여 쾌적한 상태를 유지하는 스마트 공조 시스템을 개발하는 것을 목표로 합니다.

## 💡 주요 기능
- 실시간 온도 및 습도 측정
- 자동 냉난방 모드 및 공기청정 모드 전환
- 사용자 설정 기반 수동 제어 기능
- 간단한 UI 디스플레이 출력
- TCP/IP 통신 방식을 통한 센서값 및 명령 전달

## 🛠️ 사용 기술들
- 언어 : C
- 개발 환경 : VSCode
- 하드웨어 : STM32, RaspberryPi, Arduino
- 데이터베이스 : Heidi Sql + Maria DB

---

## 📽️ 시연 영상

**먼지 센서 영상**

[![먼지 센서 영상](https://img.youtube.com/vi/PgM0-U3HY6g/0.jpg)](https://www.youtube.com/watch?v=PgM0-U3HY6g)

- 먼지 농도에 따라 높으면 빨강, 중간이면 초록, 좋으면 파란 불이 들어온다.

**자동 공조 시스템 영상**

[![자동 공조 시스템 영상](https://img.youtube.com/vi/z_D4CBkErMk/0.jpg)](https://www.youtube.com/watch?v=z_D4CBkErMk)

- 습도 및 온도에 따라 환풍기와 에어컨의 강도가 자동으로 가동된다.

---

## ✏️ 보완 사항
- 먼지 센서의 정확한 데이터 값 확보
- 적외선 센서 등을 활용한 충돌 감지 센서 탑재
