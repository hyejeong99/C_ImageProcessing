# 영상처리
OpenCV를 활용한 영상처리

- OpenCV
- C++
- [Image Processing](https://github.com/hyejeong99/ImageProcessing) : Image Processing with C++

### OpenCV를 이용한 영사처리
#### coin
fopen 함수를 fopen_s를 사용하여 수정하기

#### grayScale
![그림1](https://user-images.githubusercontent.com/59854960/113371765-0f8fcf00-93a2-11eb-8c7c-c5405e1b284c.png)

gray-scale 영상 제작
#### colorRaw
![그림2](https://user-images.githubusercontent.com/59854960/113371766-10286580-93a2-11eb-97cd-daa2f77b1a82.png)

color raw 영상 제작

#### colorN

color 비트맵 영상의 negative 영상 만들기

#### grayScaleN
![그림5](https://user-images.githubusercontent.com/59854960/113372350-72ce3100-93a3-11eb-9a9a-98bdbd3fc88a.JPG)

gray-scale 비트맵 영상의 negative 영상 만들기

#### colorBMP
![그림4](https://user-images.githubusercontent.com/59854960/113371990-8e850780-93a2-11eb-98bd-45a8ec1594b5.png)

color 비트맵 영상 생성

#### grayScaleBMP
![그림3](https://user-images.githubusercontent.com/59854960/113371988-8d53da80-93a2-11eb-9faf-5f9ebf95bfe9.png)

gray-scale 비트맵 영상 생성
#### MFC_negative

MFC를 이용한 negative 영상 생성하기

#### SN_123
(1)상수 더하기/빼기/곱하기/나누기
- 상수 곱하기: 상수 값으로 2.0을 사용하세요
- 상수 나누기: 상수 값으로 1/2.0을 사용하세요

(2)프레임 더하기/빼기/곱하기/LUT이용 곱하기
 - 프레임 곱하기: (*) 연산자 대신에 (&) 연산자를 사용하세요

(3)명암비 증가/감소
- 명암비 증가: 직선 기울기 값으로 2.0을 사용하세요
- 명암비 감소: 직선 기울기 값으로 1/2.0을 사용하세요

#### SN_456
(1)Salt&pepper 잡음 생성![1](https://user-images.githubusercontent.com/59854960/113372900-9d6cb980-93a4-11eb-826c-4dfa5ba90835.png)

- rand(): 호출될 때마다 정수 난수 값(0 ~ RAND_MAX)을 반환
- srand(): rand()  함수의 seed 값 지정에 사용
- time(): 1970년 1월 1일(GMT) 자정을 00:00:00으로 하여 현재 시각까지 지난 시간을 초(second)로 반환, time 함수를 사용하여 seed 값을 지정함 
- 잡음 비율: 2%
: 난수를  -1 과 1 사이 값으로 변환
: 난수가  (1 - 2/100) 보다 크면 salt 잡음 생성
: 난수가 -(1 - 2/100) 보다 작으면 pepper 잡음 생성

(2)bit-plane 이미지 표시

![2](https://user-images.githubusercontent.com/59854960/113372904-9e9de680-93a4-11eb-877b-2100d41bf6ed.png)

비트 평면 이미지 구하기
- 7번 비트(MSB) 평면 이미지
- 4번 비트 평면 이미지
- 0번 비트(LSB) 평면 이미지

![2-7](https://user-images.githubusercontent.com/59854960/113372909-9f367d00-93a4-11eb-9a50-500164e3d1f7.png)

7번 비트평면 이미지

![2-4](https://user-images.githubusercontent.com/59854960/113372907-9f367d00-93a4-11eb-81ad-1f5725d59a28.png)

4번 비트평면 이미지

![2-0](https://user-images.githubusercontent.com/59854960/113372905-9e9de680-93a4-11eb-9e03-cb15940e9084.png)

0번 비트평면 이미지

(3)워터마크 삽입/검출

![3](https://user-images.githubusercontent.com/59854960/113372910-9fcf1380-93a4-11eb-92f0-e5ee84ca06ed.png)

- 왼쪽 : watermark 삽입
- 오른쪽 : watermark 검출

#### histo_binary
히스토그램 그래프 작성, 영상 이진화

#### four_1
(1)동적 영상 이진화

![동적이진화](https://user-images.githubusercontent.com/59854960/113373660-54b60000-93a6-11eb-8be2-7984dfd8137d.JPG)

Slider control을 이용하여 임계치를 동적으로 입력한다.

(2)히스토그램 균등화

![히스토그램균등화](https://user-images.githubusercontent.com/59854960/113373663-554e9680-93a6-11eb-8bb0-cfaa4ab41d47.JPG)

영상의 명암값 분포를 재분배하여 출력영상의 히스토그램 분포가 균등하게 되도록 한다.

(3)히스토그램 스트레칭

![히스토그램스트레칭](https://user-images.githubusercontent.com/59854960/113373664-554e9680-93a6-11eb-9765-03db8aba3f58.JPG)

영상의 명암값 분포가 최대한 펼쳐지도록 한다.
저 명암대비 영상의 개선에 사용한다.

(3-1)히스토그램 스트레칭(기본)

![기본](https://user-images.githubusercontent.com/59854960/113373659-541d6980-93a6-11eb-8f0f-8c542c495966.JPG)

(3-2)히스토그램 스트레칭(엔드인)

![엔드인](https://user-images.githubusercontent.com/59854960/113373661-54b60000-93a6-11eb-9ba6-aad374ef19fd.JPG)

#### four_2
(1)히스토그램 명시화

![명시화](https://user-images.githubusercontent.com/59854960/113374400-073a9280-93a8-11eb-9f3c-82086a9b25e1.JPG)

![명시화2](https://user-images.githubusercontent.com/59854960/113374401-073a9280-93a8-11eb-9e8e-2a0da749c05b.JPG)

입력영상을 원하는 히스토그램을 갖는 영상으로 변환한다.
특정 gray level을 강조하여 영상을 개선할 때 사용한다.

(2)자동 영상 이진화

![otsu](https://user-images.githubusercontent.com/59854960/113374397-06096580-93a8-11eb-96ab-06df13b4f01c.JPG)

(2-1)자동 영상 이진화(Otsu)
Gray-scale 영상에서 물체 및 배경 분리에 사용한다.
배경 분리를 위한 임계값을 히스토그램 모양에서 자동 계산한다.

[가정]
• 히스토그램이 배경과 물체를 나타내는 두 개의 그룹(피크)으로 구성된다.
• 각 그룹은 정규 분포로 모델링 한다.

(2-2)적응 이진화(Sauvola)
영상 내 영역 위치에 따라, 밝기 변동을 반영하는 각각의 이진화 임계값 사용한다.
현재 위치의 주변 영역을 설정하고 그 영역내의 밝기 평균과 분산 값을 임계값 결정에 사용한다.

(3)영상 블렌딩

![블렌딩](https://user-images.githubusercontent.com/59854960/113374404-07d32900-93a8-11eb-9ab1-353639f4495f.jpg)

두 개의 영상을 섞어준다.
