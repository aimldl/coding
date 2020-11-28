* Draft: 2020-11-28 (Sat)

[코딩테스트 연습](https://programmers.co.kr/learn/challenges) > [IS NULL](https://programmers.co.kr/learn/challenges?selected_part_id=17045) > [이름이 있는 동물의 아이디](https://programmers.co.kr/learn/courses/30/lessons/59407)



###### 문제 설명

`ANIMAL_INS` 테이블은 동물 보호소에 들어온 동물의 정보를 담은 테이블입니다. `ANIMAL_INS` 테이블 구조는 다음과 같으며, `ANIMAL_ID`, `ANIMAL_TYPE`, `DATETIME`, `INTAKE_CONDITION`, `NAME`, `SEX_UPON_INTAKE`는 각각 동물의 아이디, 생물 종, 보호 시작일, 보호 시작 시 상태, 이름, 성별 및 중성화 여부를 나타냅니다.

| NAME             | TYPE       | NULLABLE |
| ---------------- | ---------- | -------- |
| ANIMAL_ID        | VARCHAR(N) | FALSE    |
| ANIMAL_TYPE      | VARCHAR(N) | FALSE    |
| DATETIME         | DATETIME   | FALSE    |
| INTAKE_CONDITION | VARCHAR(N) | FALSE    |
| NAME             | VARCHAR(N) | TRUE     |
| SEX_UPON_INTAKE  | VARCHAR(N) | FALSE    |

동물 보호소에 들어온 동물 중, **이름이 있는 동물의 ID를 조회**하는 SQL 문을 작성해주세요. **단, ID는 오름차순 정렬**되어야 합니다.

##### 예시

예를 들어 `ANIMAL_INS` 테이블이 다음과 같다면

| ANIMAL_ID | ANIMAL_TYPE | DATETIME            | INTAKE_CONDITION | NAME       | SEX_UPON_INTAKE |
| --------- | ----------- | ------------------- | ---------------- | ---------- | --------------- |
| A434523   | Cat         | 2015-11-20 14:18:00 | Normal           | NULL       | Spayed Female   |
| A562649   | Dog         | 2014-03-20 18:06:00 | Sick             | NULL       | Spayed Female   |
| A524634   | Dog         | 2015-01-02 18:54:00 | Normal           | *Belle     | Intact Female   |
| A465637   | Dog         | 2017-06-04 08:17:00 | Injured          | *Commander | Neutered Male   |

이름이 있는 동물의 ID는 A524634와 A465637입니다. 따라서 SQL을 실행하면 다음과 같이 출력되어야 합니다.

| ANIMAL_ID |
| --------- |
| A465637   |
| A524634   |

------

본 문제는 [Kaggle의 Austin Animal Center Shelter Intakes and Outcomes](https://www.kaggle.com/aaronschlegel/austin-animal-center-shelter-intakes-and-outcomes)에서 제공하는 데이터를 사용하였으며 [ODbL](https://opendatacommons.org/licenses/odbl/1.0/)의 적용을 받습니다.

## 힌트

```sql
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS WHERE NAME IS NOT NULL;
```

내용을 확인해보면 모든 `NAME`열에 값이 있습니다.

```sql
| ANIMAL_ID | NAME         |
| --------- | ------------ |
| A349996   | Sugar        |
| A350276   | Jewel        |
  ...
| A414513   | Rocky        |
```

## 정답

```sql
SELECT ANIMAL_ID FROM ANIMAL_INS WHERE NAME IS NOT NULL;
```

`ORDER BY`를 쓰지 않아도 결과는 오름차순 정렬이 됩니다.

```sql
| ANIMAL_ID |
| --------- |
| A349996   |
| A350276   |
| A350375   |
| A352555   |
| A352713   |
| A352872   |
| A353259   |
| A354540   |
| A354597   |
| A354725   |
| A354753   |
| A355519   |
| A355688   |
| A355753   |
| A357021   |
| A357444   |
| A357846   |
| A358697   |
| A358879   |
| A361391   |
| A362103   |
| A362383   |
| A362707   |
| A362967   |
| A363653   |
| A364429   |
| A365172   |
| A365302   |
| A367012   |
| A367438   |
| A367747   |
| A368742   |
| A370439   |
| A370507   |
| A370852   |
| A371000   |
| A371102   |
| A371344   |
| A371534   |
| A373219   |
| A373687   |
| A375393   |
| A376322   |
| A376459   |
| A377750   |
| A378348   |
| A378353   |
| A378818   |
| A378946   |
| A379998   |
| A380009   |
| A380320   |
| A380420   |
| A380506   |
| A381173   |
| A381217   |
| A382192   |
| A382251   |
| A383036   |
| A383964   |
| A384360   |
| A384568   |
| A385442   |
| A386005   |
| A386276   |
| A386688   |
| A387083   |
| A387965   |
| A388360   |
| A388691   |
| A390222   |
| A391512   |
| A391858   |
| A392027   |
| A392075   |
| A392615   |
| A394547   |
| A395451   |
| A396810   |
| A397882   |
| A399421   |
| A399552   |
| A400498   |
| A400680   |
| A403564   |
| A405494   |
| A406756   |
| A407156   |
| A408035   |
| A409637   |
| A410330   |
| A410668   |
| A410684   |
| A412173   |
| A412626   |
| A412697   |
| A413789   |
| A414198   |
| A414513   |
```