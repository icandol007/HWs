# 🖥️ 수업 중 학생 표정에 따른 관심도 모니터링 앱
**클라우드컴퓨팅 텀 프로젝트 14조**
## 🧑‍🤝‍🧑역할 분담
- **201824579 정영진**: 팀장, UI설계 및 모바일 애플리케이션 개발
- **202255671 정연수**: UI 설계 및 모바일 애플리케이션 개발
- **201912345 김민재**: 이미지 학습 및 백엔드 개발
- **201924566 전원균**: 백엔드 개발

## ✅프로젝트 소개
수업 중 학생 표정에 따른 관심도 모니터링 앱은 수업 중 학생들의 사진을 주기적으로 촬영해 표정을 분석하여 수업에 대한 관심도를 모니터링하고, 이를 토대로 강의자가 학생들이 수업 내용에 얼마나 관심을 가지고 있는지 파악할 수 있게 도움을 준다.

학생들이 자신의 기기(스마트폰, 태블릿 등)를 사용하여 주기적으로 사진을 촬영하면 AWS Rekognition을 사용하여 해당 사진에서 얼굴 인식과 감정 분석이 수행된다. 
분석된 데이터는 AWS DynamoDB에 저장되며 이를 통해 교사는 학생들의 수업 집중도를 파악하고, 수업 방식을  조정하는 등의 방법을 통해 학생들의 수업 집중도를 높일 수 있을 것이다.

## 🎯프로젝트의 필요성
최근의 교육 환경은 전통적인 대면 수업 뿐 아니라 온라인 비대면 수업도 많은 비율을 차지한다. 직접적으로 학생들을 마주하는 수업이 아닌 비대면 수업 환경에서는 강의자가 학생들이 수업에 얼마나 많은 관심을 갖고 참여하는지 알 방법이 비교적 적은 것이 사실이다.

대면 수업을 진행함에도 강의자가 학생들의 반응을 알기 어려운 경우 또한 존재한다. 많은 학생이 참여하는 대규모 강의가 그렇다. 대규모 강의에서는 강의자가 개별 학생들의 반응을 즉각적으로 파악하기 어려워 많은 학생들이 수업에 집중 중인지 또는 이해하고 있는지 그 여부를 파악하기 힘들다.

이러한 문제를 해결하기 위해 본 프로젝트는 학생들의 표정을 분석하여 수업에 대한 관심도를 실시간으로 모니터링하는 시스템을 제시한다. 해당 시스템이 필요한 이유는 다음과 같은 몇 가지로 정리할 수 있다.

1. **실시간 피드백 제공**: 강의자는 실시간으로 학생들의 집중도를 확인하고 수업 방식을 즉각적으로 조정할 수 있다. 예를 들어, 학생들의 관심도가 떨어지면 잠깐의 휴식 시간을 부여하는 등의 방법이 있겠다.
2. **강의 품질 향상**: 학생들의 감정 데이터를 분석하여 강의자에게 수업 후 피드백을 제공하고 이를 통해 수업의 품질을 지속적으로 개선할 수 있다.
3. **교육 방법론 연구**: 수집된 데이터를 바탕으로 교육 방법론을 연구하고 데이터 기반 의사결정을 통해 교육 정책을 개선해 장기적으로 교육의 질을 높이는 데 도움을 줄 수 있다.

따라서 본 프로젝트는 학생들의 학습 상태를 정확하게 파악하고 학습 효율성을 극대화하기 위한 도구로 사용될 수 있을 것이다.

## 🛠️관련 기술
### AWS Rekognition
AWS에서 제공하는 컴퓨터 비전 서비스로 이미지에서 오브젝트나 사람, 텍스트 등을 분석하는 데 사용된다. 본 프로젝트에서는 그 중 감정 분석 기능을 활용하고자 하였다.

AWS Rekognition은 이미지에서 얼굴의 표정을 분석하여 감정 상태를 추론해 웃음, 놀람, 화남, 슬픔 등 다양한 감정을 감지할 수 있다.
본 프로젝트에서는 감정 분석 기능을 사용하여 수업을 듣는 학생들의 표정을 분석하고, 이를 바탕으로 학습 관심도를 평가한다. 예를 들어 학생이 수업 중에 웃고 있는지, 혼란스러워하는지 등을 분석하여 주기적으로 강의자에게 피드백을 제공한다.

AWS Rekognition은 고도의 정확성을 가지고 있어 얼굴 인식과 감정 분석에서 신뢰할 수 있는 결과를 제공한다. 또한 AWS의 다른 서비스와 쉽게 통합할 수 있어 AWS 서비스를 이용해 서버리스 백엔드를 구축하는 본 프로젝트에서 사용하기 적합하다 판단하였다.

### 서버리스 아키텍처
서버리스 아키텍처는 개발자가 기본 아키텍처를 관리하지 않고 애플리케이션을 빌드하고 관리할 수 있는 소프트웨어 설계 접근 방식을 뜻한다. 
AWS에서는 서버리스 아키텍처를 위한 여러 기능을 지원하여 개발자들이 인프라 관리에 신경 쓰지 않고 코드를 작성하고 배포할 수 있도록 돕는다. 
AWS의 서버리스 서비스는 자동으로 리소스를 할당하고 조정하며, 사용한 만큼만 비용을 지불하도록 설계되어 있어 효율적이다. AWS가 제공하는 서비스 중 본 프로젝트에서 사용하는 것은 아래와 같다.

- **AWS Lambda**: 서버를 프로비저닝하거나 관리할 필요 없이 코드를 실행할 수 있는 서버리스 컴퓨팅 서비스이다. Lambda는 이벤트에 의해 트리거되며, 개발자는 비즈니스 로직에만 집중할 수 있는 효과를 가져온다. 또한 Lambda 함수는 자동으로 확장되고 사용한 만큼만 비용이 청구되기 때문에 경제적이다.
- **API Gateway**: RESTful API와 WebSocket API를 생성, 배포 및 관리할 수 있는 완전 관리형 서비스로 백엔드와 클라이언트를 연결하는 엔드포인트 역할을 수행한다. 이를 통해 앱, 웹 등의 다양한 클라이언트에서 백엔드 서비스에 접근할 수 있다. API Gateway는 요청과 응답을 라우팅하고, 필요시 인증 및 권한 부여, 트래픽 관리, 모니터링 등의 기능을 제공한다.
- **AWS S3(Simple Storage Service)**: 객체 스토리지 서비스로 대량의 데이터를 저장 및 관리할 수 있다. 이미지나 비디오 등 정적 파일을 S3에 저장하고 필요할 때마다 이를 Lambda나 다른 서비스에서 접근할 수 있도록 한다. S3는 높은 가용성을 제공해 데이터를 안전하게 보관할 수 있다.
- **AWS DynamoDB**: 빠르고 유연한 NoSQL 데이터베이스 서비스로 빠른 응답 시간과 제한 없이 확장 가능한 용량을 제공한다. 서버리스 앱에서 DynamoDB는 구조화된 데이터를 저장하고 조회하는 데 유용하게 사용된다. DynamoDB는 완전 관리형 서비스로 자동으로 스케일링되며 개발자가 데이터베이스를 관리 및 운영할 필요를 없애준다.

위와 같은 AWS의 서비스를 이용해 서버리스 아키텍처를 구축하였다. 서버리스 아키텍처를 도입함으로써 인프라 관리에 대한 부담을 줄이고 동시에 서버리스 아키텍처의 장점인 확장성, 비용 효율성, 빠른 배포 속도 등을 불러올 수 있다.

## 📋프로젝트 결과
본 프로젝트에서 구현한 시스템의 대략적인 다이어그램은 아래와 같다.

![시스템 다이어그램](https://github.com/icandol007/HWs/blob/master/%EC%A0%9C%EB%AA%A9%20%EC%97%86%EB%8A%94%20%EB%8B%A4%EC%9D%B4%EC%96%B4%EA%B7%B8%EB%9E%A8.drawio.png)

- **모바일 애플리케이션**: 주기적으로 사진을 촬영해 S3에 업로드한다.
- **AWS API Gateway**: 모바일 앱과 백엔드(Lambda)간의 엔드포인트를 제공한다. HTTP 요청을 받아 Lambda함수로 라우팅한다.
- **AWS Lambda**: 서버리스 함수로 API Gateway에서 전달된 요청을 처리하고 감정 분석을 수행하며 그 결과를 DynamoDB에 저장한다.
- **AWS Rekognition**: Lambda 함수가 S3에서 가져온 사진을 Rekognition에 보내면 얼굴을 인식하고 감정을 분석하여 그 결과를 반환한다.
- **AWS S3**: 모바일 앱에서 업로드한 학생들의 얼굴 사진이 저장된다.
- **AWS DynamoDB**: 각 학생의 얼굴 인식 결과와 감정 분석 결과가 DynamoDB에 기록된다.

데이터 흐름은 다음과 같다.
1. **모바일 애플리케이션**에서 얼굴 사진을 촬영하고 이 사진을 **AWS S3** 버킷에 업로드한다.
2. **모바일 애플리케이션**은 업로드된 사진의 키(key)를 포함하여 **AWS API Gateway**로 HTTP 요청을 보낸다.
3. **API Gateway**는 요청을 받아서 **AWS Lambda** 함수로 전달한다.
4. **Lambda** 함수는 **S3**에서 사진을 다운로드하고 **AWS Rekognition**을 호출하여 감정 분석을 수행한다. Smile, Confused 등 분석된 결과는 **DynamoDB**에 저장된다.
5. **Lambda** 함수는 분석 결과를 **API Gateway**를 통해 **모바일 애플리케이션**으로 응답한다.

## 📱사용 방법
TODO

## 활용 방안
- **실시간 관심도 모니터링**: 강의자가 수업 중 학생들의 관심도를 모니터링하여 수업의 진행 방식을 즉각적으로 조정할 수 있다.
- **수업 품질 향상**: 학생들의 감정 분석 데이터를 바탕으로 수업 후 피드백을 제공하여 전반적인 수업 품질을 향상시킬 수 있다.
- **교육 방법론 연구**: 수집된 데이터를 활용하여 교육 방법론 연구에 기여할 수 있다.

