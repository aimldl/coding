* Draft: 2020-11-27 (Fri)

# [SELECT](https://programmers.co.kr/learn/challenges?selected_part_id=17042) > 어린 동물 찾기

## Problem

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

동물 보호소에 들어온 동물 중 **젊은 동물[1](https://programmers.co.kr/learn/courses/30/lessons/59037#fn1)**의 **아이디와 이름을 조회**하는 SQL 문을 작성해주세요. 이때 **결과는 아이디 순으로 조회**해주세요.

##### 예시

예를 들어 `ANIMAL_INS` 테이블이 다음과 같다면

| ANIMAL_ID | ANIMAL_TYPE | DATETIME            | INTAKE_CONDITION | NAME     | SEX_UPON_INTAKE |
| --------- | ----------- | ------------------- | ---------------- | -------- | --------------- |
| A365172   | Dog         | 2014-08-26 12:53:00 | Normal           | Diablo   | Neutered Male   |
| A367012   | Dog         | 2015-09-16 09:06:00 | Sick             | Miller   | Neutered Male   |
| A365302   | Dog         | 2017-01-08 16:34:00 | Aged             | Minnie   | Spayed Female   |
| A381217   | Dog         | 2017-07-08 09:41:00 | Sick             | Cherokee | Neutered Male   |

이 중 젊은 동물은 Diablo, Miller, Cherokee입니다. 따라서 SQL문을 실행하면 다음과 같이 나와야 합니다.

| ANIMAL_ID | NAME     |
| --------- | -------- |
| A365172   | Diablo   |
| A367012   | Miller   |
| A381217   | Cherokee |

------

본 문제는 [Kaggle의 Austin Animal Center Shelter Intakes and Outcomes](https://www.kaggle.com/aaronschlegel/austin-animal-center-shelter-intakes-and-outcomes)에서 제공하는 데이터를 사용하였으며 [ODbL](https://opendatacommons.org/licenses/odbl/1.0/)의 적용을 받습니다. 

1. `INTAKE_CONDITION`이 Aged가 아닌 경우를 뜻함 [↩](https://programmers.co.kr/learn/courses/30/lessons/59037#fnref1)

## Solution

```sql
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS WHERE INTAKE_CONDITION <> 'Aged' ORDER BY ANIMAL_ID;
# or
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS WHERE NOT INTAKE_CONDITION = 'Aged' ORDER BY ANIMAL_ID;
```

## Caution

None of the following sytax is correct. Do use `<>` for not equal to.

```sql
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS WHERE INTAKE_CONDITION != 'Aged' ORDER BY ANIMAL_ID;
# or
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS WHERE INTAKE_CONDITION NOT = 'Aged' ORDER BY ANIMAL_ID;
```

## Hint

> Source: [SQL | NOT Operator](https://www.geeksforgeeks.org/sql-not-operator/), GeeksforGeeks
>
> ### Syntax
>
> ```sql
> # comment
> SELECT column1, colomn2, … FROM table_name WHERE NOT condition;
> ```
>
> ### Examples
>
> ```sql
> # comment
> SELECT * FROM Customers WHERE NOT Country=’UK’;
>  ELECT * FROM Customers WHERE NOT Country=’USA’ AND NOT Country=’UK’;
> ```

## Result

```sql
| ANIMAL_ID | NAME         |
| --------- | ------------ |
| A349996   | Sugar        |
| A350276   | Jewel        |
| A350375   | Meo          |
| A352555   | Harley       |
| A352713   | Gia          |
| A353259   | Bj           |
| A354540   | Tux          |
| A354597   | Ariel        |
| A354725   | Kia          |
| A354753   | Sammy        |
| A355519   | Faith        |
| A355688   | Shadow       |
| A355753   | Elijah       |
| A357021   | Queens       |
| A357444   | Puppy        |
| A357846   | Happy        |
| A358697   | Fuzzo        |
| A358879   | Simba        |
| A361391   | Baby Bear    |
| A362103   | Stitch       |
| A362383   | *Morado      |
| A362707   | Girly Girl   |
| A362967   | Honey        |
| A363653   | Goofy        |
| A364429   | Hugo         |
| A365172   | Diablo       |
| A367012   | Miller       |
| A367438   | Cookie       |
| A367747   | Woody        |
| A368930   |              |
| A370439   | Sniket       |
| A370507   | Emily        |
| A370852   | Katie        |
| A371000   | Greg         |
| A371102   | Ceballo      |
| A371344   | Sailor       |
| A371534   | April        |
| A373219   | Ella         |
| A373687   | Rosie        |
| A376322   | Mama Dog     |
| A376459   | Dora         |
| A377750   | Lucy         |
| A378348   | Frijolito    |
| A378818   | Zoe          |
| A378946   | Mercedes     |
| A379998   | Disciple     |
| A380009   | Pickle       |
| A380320   | Scooby       |
| A380420   | Laika        |
| A380506   | Ruby         |
| A381173   | Pepper       |
| A381217   | Cherokee     |
| A382192   | Maxwell 2    |
| A382251   | Princess     |
| A383036   | Oreo         |
| A383964   | Finney       |
| A384360   | Jj           |
| A384568   | Jedi         |
| A385442   | Clyde        |
| A386005   | Giovanni     |
| A386276   | Tiko         |
| A387083   | Goldie       |
| A387965   | Dakota       |
| A388360   | Spider       |
| A388691   | Blaze        |
| A390222   | Holly        |
| A391512   | Rome         |
| A391858   | Nellie       |
| A392027   | Penny        |
| A392075   | Skips        |
| A392615   | Chip         |
| A394547   | Snickerdoodl |
| A395451   | Rogan        |
| A396810   | Raven        |
| A397882   | Charlie      |
| A399421   | Lucy         |
| A399552   | Jack         |
| A400498   | Reggie       |
| A400680   | Lucy         |
| A403564   | Anna         |
| A405494   | Kaila        |
| A406756   | Sabrina      |
| A407156   | Jake         |
| A408035   | Lizzie       |
| A410330   | Chewy        |
| A410668   | Raven        |
| A410684   | Mitty        |
| A412173   | Jimminee     |
| A412626   | *Sam         |
| A412697   | Jackie       |
| A413789   | Benji        |
| A414198   | Shelly       |
| A414513   | Rocky        |
```
