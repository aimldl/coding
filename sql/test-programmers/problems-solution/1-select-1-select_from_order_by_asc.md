* Draft: 2020-11-27 (Fri)

# [SELECT](https://programmers.co.kr/learn/challenges?selected_part_id=17042) > 모든 레코드 조회하기

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

동물 보호소에 들어온 모든 동물의 정보를 ANIMAL_ID순으로 조회하는 SQL문을 작성해주세요. SQL을 실행하면 다음과 같이 출력되어야 합니다.

| ANIMAL_ID | ANIMAL_TYPE | DATETIME            | INTAKE_CONDITION | NAME   | SEX_UPON_INTAKE |
| --------- | ----------- | ------------------- | ---------------- | ------ | --------------- |
| A349996   | Cat         | 2018-01-22 14:32:00 | Normal           | Sugar  | Neutered Male   |
| A350276   | Cat         | 2017-08-13 13:50:00 | Normal           | Jewel  | Spayed Female   |
| A350375   | Cat         | 2017-03-06 15:01:00 | Normal           | Meo    | Neutered Male   |
| A352555   | Dog         | 2014-08-08 04:20:00 | Normal           | Harley | Spayed Female   |

본 문제는 [Kaggle의 Austin Animal Center Shelter Intakes and Outcomes](https://www.kaggle.com/aaronschlegel/austin-animal-center-shelter-intakes-and-outcomes)에서 제공하는 데이터를 사용하였으며 [ODbL](https://opendatacommons.org/licenses/odbl/1.0/)의 적용을 받습니다.

## Solution

```sql
SELECT * FROM ANIMAL_INS ORDER BY ANIMAL_ID;
```

## Hint

> Source: [SQL | ORDER BY](https://www.geeksforgeeks.org/sql-order-by/), GeeksforGeeks
>
> ### Syntax
>
> ```sql
> # One column
> SELECT * FROM table_name ORDER BY column_name ASC|DESC
> # Multiple columns
> SELECT * FROM table_name ORDER BY column1 ASC|DESC , column2 ASC|DESC
> ```
>
> ### Examples
>
> ```sql
> SELECT * FROM Student ORDER BY ROLL_NO DESC;
> SELECT * FROM Student ORDER BY Age ASC , ROLL_NO DESC;
> SELECT * FROM Student ORDER BY Age , ROLL_NO DESC;
> ```

## Result

```sql
| ANIMAL_ID | ANIMAL_TYPE | DATETIME            | INTAKE_CONDITION | NAME         | SEX_UPON_INTAKE |
| --------- | ----------- | ------------------- | ---------------- | ------------ | --------------- |
| A349996   | Cat         | 2018-01-22 14:32:00 | Normal           | Sugar        | Neutered Male   |
| A350276   | Cat         | 2017-08-13 13:50:00 | Normal           | Jewel        | Spayed Female   |
| A350375   | Cat         | 2017-03-06 15:01:00 | Normal           | Meo          | Neutered Male   |
| A352555   | Dog         | 2014-08-08 04:20:00 | Normal           | Harley       | Spayed Female   |
| A352713   | Cat         | 2017-04-13 16:29:00 | Normal           | Gia          | Spayed Female   |
| A352872   | Dog         | 2015-07-09 17:51:00 | Aged             | Peanutbutter | Neutered Male   |
| A353259   | Dog         | 2016-05-08 12:57:00 | Injured          | Bj           | Neutered Male   |
| A354540   | Cat         | 2014-12-11 11:48:00 | Normal           | Tux          | Neutered Male   |
| A354597   | Cat         | 2014-05-02 12:16:00 | Normal           | Ariel        | Spayed Female   |
| A354725   | Dog         | 2015-08-26 11:51:00 | Normal           | Kia          | Spayed Female   |
| A354753   | Dog         | 2017-04-21 11:33:00 | Normal           | Sammy        | Neutered Male   |
| A355519   | Dog         | 2015-05-08 18:34:00 | Normal           | Faith        | Spayed Female   |
| A355688   | Dog         | 2014-01-26 13:48:00 | Normal           | Shadow       | Neutered Male   |
| A355753   | Dog         | 2015-09-10 13:14:00 | Normal           | Elijah       | Neutered Male   |
| A357021   | Dog         | 2014-12-03 15:15:00 | Normal           | Queens       | Spayed Female   |
| A357444   | Dog         | 2016-03-11 15:43:00 | Normal           | Puppy        | Neutered Male   |
| A357846   | Dog         | 2016-03-17 14:09:00 | Normal           | Happy        | Neutered Male   |
| A358697   | Dog         | 2015-02-06 12:12:00 | Normal           | Fuzzo        | Neutered Male   |
| A358879   | Dog         | 2015-09-14 16:52:00 | Normal           | Simba        | Neutered Male   |
| A361391   | Dog         | 2015-03-30 11:36:00 | Normal           | Baby Bear    | Neutered Male   |
| A362103   | Dog         | 2014-11-18 21:20:00 | Normal           | Stitch       | Neutered Male   |
| A362383   | Dog         | 2016-04-21 08:19:00 | Normal           | *Morado      | Neutered Male   |
| A362707   | Dog         | 2016-01-27 12:27:00 | Sick             | Girly Girl   | Spayed Female   |
| A362967   | Dog         | 2014-06-08 18:19:00 | Normal           | Honey        | Spayed Female   |
| A363653   | Dog         | 2014-11-17 17:39:00 | Normal           | Goofy        | Neutered Male   |
| A364429   | Dog         | 2015-09-28 16:26:00 | Normal           | Hugo         | Neutered Male   |
| A365172   | Dog         | 2014-08-26 12:53:00 | Normal           | Diablo       | Neutered Male   |
| A365302   | Dog         | 2017-01-08 16:34:00 | Aged             | Minnie       | Spayed Female   |
| A367012   | Dog         | 2015-09-16 09:06:00 | Sick             | Miller       | Neutered Male   |
| A367438   | Dog         | 2015-09-10 16:01:00 | Normal           | Cookie       | Spayed Female   |
| A367747   | Dog         | 2014-10-19 14:49:00 | Normal           | Woody        | Neutered Male   |
| A368742   | Dog         | 2018-02-03 10:40:00 | Aged             | Stormy       | Spayed Female   |
| A368930   | Dog         | 2014-06-08 13:20:00 | Normal           |              | Spayed Female   |
| A370439   | Dog         | 2016-06-25 11:46:00 | Normal           | Sniket       | Neutered Male   |
| A370507   | Cat         | 2014-10-27 14:43:00 | Normal           | Emily        | Spayed Female   |
| A370852   | Dog         | 2013-11-03 15:04:00 | Normal           | Katie        | Spayed Female   |
| A371000   | Cat         | 2015-07-29 16:07:00 | Normal           | Greg         | Neutered Male   |
| A371102   | Dog         | 2015-08-03 09:09:00 | Normal           | Ceballo      | Neutered Male   |
| A371344   | Dog         | 2015-05-11 12:33:00 | Normal           | Sailor       | Neutered Male   |
| A371534   | Dog         | 2016-06-07 17:42:00 | Normal           | April        | Spayed Female   |
| A373219   | Cat         | 2014-07-29 11:43:00 | Normal           | Ella         | Spayed Female   |
| A373687   | Dog         | 2014-03-20 12:31:00 | Normal           | Rosie        | Spayed Female   |
| A375393   | Dog         | 2015-06-12 12:47:00 | Aged             | Dash         | Neutered Male   |
| A376322   | Dog         | 2014-02-18 12:24:00 | Normal           | Mama Dog     | Spayed Female   |
| A376459   | Dog         | 2017-07-09 07:42:00 | Normal           | Dora         | Spayed Female   |
| A377750   | Dog         | 2017-10-25 17:17:00 | Normal           | Lucy         | Spayed Female   |
| A378348   | Dog         | 2014-01-25 14:38:00 | Normal           | Frijolito    | Neutered Male   |
| A378353   | Dog         | 2014-08-02 11:23:00 | Aged             | Lyla         | Intact Female   |
| A378818   | Dog         | 2014-07-05 07:13:00 | Normal           | Zoe          | Spayed Female   |
| A378946   | Dog         | 2017-09-28 13:36:00 | Normal           | Mercedes     | Spayed Female   |
| A379998   | Dog         | 2013-10-23 11:42:00 | Normal           | Disciple     | Intact Male     |
| A380009   | Dog         | 2016-02-01 14:35:00 | Normal           | Pickle       | Spayed Female   |
| A380320   | Dog         | 2014-02-03 12:41:00 | Normal           | Scooby       | Neutered Male   |
| A380420   | Dog         | 2017-08-04 16:45:00 | Normal           | Laika        | Spayed Female   |
| A380506   | Dog         | 2016-01-22 17:13:00 | Normal           | Ruby         | Spayed Female   |
| A381173   | Dog         | 2014-08-06 12:07:00 | Normal           | Pepper       | Spayed Female   |
| A381217   | Dog         | 2017-07-08 09:41:00 | Sick             | Cherokee     | Neutered Male   |
| A382192   | Dog         | 2015-03-13 13:14:00 | Normal           | Maxwell 2    | Intact Male     |
| A382251   | Dog         | 2014-11-08 16:14:00 | Normal           | Princess     | Spayed Female   |
| A383036   | Cat         | 2014-05-29 12:31:00 | Normal           | Oreo         | Neutered Male   |
| A383964   | Dog         | 2017-02-05 12:27:00 | Normal           | Finney       | Neutered Male   |
| A384360   | Cat         | 2014-07-04 01:55:00 | Injured          | Jj           | Neutered Male   |
| A384568   | Cat         | 2014-12-13 15:19:00 | Normal           | Jedi         | Neutered Male   |
| A385442   | Dog         | 2014-01-11 15:15:00 | Normal           | Clyde        | Neutered Male   |
| A386005   | Dog         | 2015-09-25 18:17:00 | Normal           | Giovanni     | Neutered Male   |
| A386276   | Cat         | 2015-12-19 12:52:00 | Normal           | Tiko         | Neutered Male   |
| A386688   | Dog         | 2015-08-17 12:55:00 | Aged             | Punch        | Neutered Male   |
| A387083   | Dog         | 2014-02-01 18:36:00 | Normal           | Goldie       | Spayed Female   |
| A387965   | Dog         | 2014-06-25 16:58:00 | Sick             | Dakota       | Spayed Female   |
| A388360   | Dog         | 2015-12-25 10:13:00 | Sick             | Spider       | Neutered Male   |
| A388691   | Dog         | 2015-11-27 15:59:00 | Normal           | Blaze        | Neutered Male   |
| A390222   | Dog         | 2013-12-08 17:04:00 | Normal           | Holly        | Spayed Female   |
| A391512   | Dog         | 2016-04-06 15:53:00 | Normal           | Rome         | Neutered Male   |
| A391858   | Dog         | 2017-03-16 16:53:00 | Normal           | Nellie       | Spayed Female   |
| A392027   | Dog         | 2014-01-31 13:46:00 | Normal           | Penny        | Spayed Female   |
| A392075   | Dog         | 2013-11-20 13:09:00 | Normal           | Skips        | Neutered Male   |
| A392615   | Dog         | 2015-07-26 11:39:00 | Normal           | Chip         | Neutered Male   |
| A394547   | Dog         | 2015-01-24 16:14:00 | Normal           | Snickerdoodl | Spayed Female   |
| A395451   | Dog         | 2015-12-27 17:42:00 | Normal           | Rogan        | Neutered Male   |
| A396810   | Dog         | 2016-08-22 16:13:00 | Injured          | Raven        | Spayed Female   |
| A397882   | Dog         | 2017-07-12 14:43:00 | Injured          | Charlie      | Neutered Male   |
| A399421   | Dog         | 2015-08-25 14:08:00 | Normal           | Lucy         | Spayed Female   |
| A399552   | Dog         | 2013-10-14 15:38:00 | Normal           | Jack         | Neutered Male   |
| A400498   | Dog         | 2016-10-04 20:31:00 | Normal           | Reggie       | Neutered Male   |
| A400680   | Dog         | 2017-06-17 13:29:00 | Normal           | Lucy         | Spayed Female   |
| A403564   | Dog         | 2013-11-18 17:03:00 | Normal           | Anna         | Spayed Female   |
| A405494   | Dog         | 2014-05-16 14:17:00 | Normal           | Kaila        | Spayed Female   |
| A406756   | Dog         | 2016-05-12 20:23:00 | Injured          | Sabrina      | Spayed Female   |
| A407156   | Dog         | 2016-10-18 11:01:00 | Normal           | Jake         | Neutered Male   |
| A408035   | Dog         | 2014-12-25 12:02:00 | Normal           | Lizzie       | Spayed Female   |
| A409637   | Dog         | 2016-04-02 11:36:00 | Aged             | Stanley      | Neutered Male   |
| A410330   | Dog         | 2016-09-11 14:09:00 | Sick             | Chewy        | Intact Female   |
| A410668   | Cat         | 2015-11-19 13:41:00 | Normal           | Raven        | Spayed Female   |
| A410684   | Cat         | 2014-06-21 12:25:00 | Normal           | Mitty        | Spayed Female   |
| A412173   | Dog         | 2015-07-28 18:17:00 | Normal           | Jimminee     | Neutered Male   |
| A412626   | Dog         | 2016-03-13 11:17:00 | Normal           | *Sam         | Neutered Male   |
| A412697   | Dog         | 2016-01-03 16:25:00 | Normal           | Jackie       | Neutered Male   |
| A413789   | Dog         | 2016-04-19 13:28:00 | Normal           | Benji        | Spayed Female   |
| A414198   | Dog         | 2015-01-29 15:01:00 | Normal           | Shelly       | Spayed Female   |
| A414513   | Dog         | 2016-06-07 09:17:00 | Normal           | Rocky        | Neutered Male   |
```