* Draft: 2020-11-27 (Fri)

# [SELECT](https://programmers.co.kr/learn/challenges?selected_part_id=17042) > 역순 정렬하기

## Problem

###### 문제 설명

`ANIMAL_INS` 테이블은 동물 보호소에 들어온 동물의 정보를 담은 테이블입니다. `ANIMAL_INS` 테이블 구조는 다음과 같으며, `ANIMAL_ID`, `ANIMAL_TYPE`, `DATETIME`, `INTAKE_CONDITION`, `NAME`, `SEX_UPON_INTAKE`는 각각 동물의 아이디, 생물 종, **보호 시작일**, 보호 시작 시 상태, **이름**, 성별 및 중성화 여부를 나타냅니다.

| NAME             | TYPE       | NULLABLE |
| ---------------- | ---------- | -------- |
| ANIMAL_ID        | VARCHAR(N) | FALSE    |
| ANIMAL_TYPE      | VARCHAR(N) | FALSE    |
| DATETIME         | DATETIME   | FALSE    |
| INTAKE_CONDITION | VARCHAR(N) | FALSE    |
| NAME             | VARCHAR(N) | TRUE     |
| SEX_UPON_INTAKE  | VARCHAR(N) | FALSE    |

동물 보호소에 들어온 **모든 동물의 이름과 보호 시작일을 조회**하는 SQL문을 작성해주세요. 이때 결과는 **ANIMAL_ID 역순으로 보여주세요**. SQL을 실행하면 다음과 같이 출력되어야 합니다.

| NAME   | DATETIME            |
| ------ | ------------------- |
| Rocky  | 2016-06-07 09:17:00 |
| Shelly | 2015-01-29 15:01:00 |
| Benji  | 2016-04-19 13:28:00 |
| Jackie | 2016-01-03 16:25:00 |
| *Sam   | 2016-03-13 11:17:00 |

..이하 생략

------

본 문제는 [Kaggle의 Austin Animal Center Shelter Intakes and Outcomes](https://www.kaggle.com/aaronschlegel/austin-animal-center-shelter-intakes-and-outcomes)에서 제공하는 데이터를 사용하였으며 [ODbL](https://opendatacommons.org/licenses/odbl/1.0/)의 적용을 받습니다.

## Solution

```sql
SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY ANIMAL_ID DESC;
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
| NAME         | DATETIME            |
| ------------ | ------------------- |
| Rocky        | 2016-06-07 09:17:00 |
| Shelly       | 2015-01-29 15:01:00 |
| Benji        | 2016-04-19 13:28:00 |
| Jackie       | 2016-01-03 16:25:00 |
| *Sam         | 2016-03-13 11:17:00 |
| Jimminee     | 2015-07-28 18:17:00 |
| Mitty        | 2014-06-21 12:25:00 |
| Raven        | 2015-11-19 13:41:00 |
| Chewy        | 2016-09-11 14:09:00 |
| Stanley      | 2016-04-02 11:36:00 |
| Lizzie       | 2014-12-25 12:02:00 |
| Jake         | 2016-10-18 11:01:00 |
| Sabrina      | 2016-05-12 20:23:00 |
| Kaila        | 2014-05-16 14:17:00 |
| Anna         | 2013-11-18 17:03:00 |
| Lucy         | 2017-06-17 13:29:00 |
| Reggie       | 2016-10-04 20:31:00 |
| Jack         | 2013-10-14 15:38:00 |
| Lucy         | 2015-08-25 14:08:00 |
| Charlie      | 2017-07-12 14:43:00 |
| Raven        | 2016-08-22 16:13:00 |
| Rogan        | 2015-12-27 17:42:00 |
| Snickerdoodl | 2015-01-24 16:14:00 |
| Chip         | 2015-07-26 11:39:00 |
| Skips        | 2013-11-20 13:09:00 |
| Penny        | 2014-01-31 13:46:00 |
| Nellie       | 2017-03-16 16:53:00 |
| Rome         | 2016-04-06 15:53:00 |
| Holly        | 2013-12-08 17:04:00 |
| Blaze        | 2015-11-27 15:59:00 |
| Spider       | 2015-12-25 10:13:00 |
| Dakota       | 2014-06-25 16:58:00 |
| Goldie       | 2014-02-01 18:36:00 |
| Punch        | 2015-08-17 12:55:00 |
| Tiko         | 2015-12-19 12:52:00 |
| Giovanni     | 2015-09-25 18:17:00 |
| Clyde        | 2014-01-11 15:15:00 |
| Jedi         | 2014-12-13 15:19:00 |
| Jj           | 2014-07-04 01:55:00 |
| Finney       | 2017-02-05 12:27:00 |
| Oreo         | 2014-05-29 12:31:00 |
| Princess     | 2014-11-08 16:14:00 |
| Maxwell 2    | 2015-03-13 13:14:00 |
| Cherokee     | 2017-07-08 09:41:00 |
| Pepper       | 2014-08-06 12:07:00 |
| Ruby         | 2016-01-22 17:13:00 |
| Laika        | 2017-08-04 16:45:00 |
| Scooby       | 2014-02-03 12:41:00 |
| Pickle       | 2016-02-01 14:35:00 |
| Disciple     | 2013-10-23 11:42:00 |
| Mercedes     | 2017-09-28 13:36:00 |
| Zoe          | 2014-07-05 07:13:00 |
| Lyla         | 2014-08-02 11:23:00 |
| Frijolito    | 2014-01-25 14:38:00 |
| Lucy         | 2017-10-25 17:17:00 |
| Dora         | 2017-07-09 07:42:00 |
| Mama Dog     | 2014-02-18 12:24:00 |
| Dash         | 2015-06-12 12:47:00 |
| Rosie        | 2014-03-20 12:31:00 |
| Ella         | 2014-07-29 11:43:00 |
| April        | 2016-06-07 17:42:00 |
| Sailor       | 2015-05-11 12:33:00 |
| Ceballo      | 2015-08-03 09:09:00 |
| Greg         | 2015-07-29 16:07:00 |
| Katie        | 2013-11-03 15:04:00 |
| Emily        | 2014-10-27 14:43:00 |
| Sniket       | 2016-06-25 11:46:00 |
|              | 2014-06-08 13:20:00 |
| Stormy       | 2018-02-03 10:40:00 |
| Woody        | 2014-10-19 14:49:00 |
| Cookie       | 2015-09-10 16:01:00 |
| Miller       | 2015-09-16 09:06:00 |
| Minnie       | 2017-01-08 16:34:00 |
| Diablo       | 2014-08-26 12:53:00 |
| Hugo         | 2015-09-28 16:26:00 |
| Goofy        | 2014-11-17 17:39:00 |
| Honey        | 2014-06-08 18:19:00 |
| Girly Girl   | 2016-01-27 12:27:00 |
| *Morado      | 2016-04-21 08:19:00 |
| Stitch       | 2014-11-18 21:20:00 |
| Baby Bear    | 2015-03-30 11:36:00 |
| Simba        | 2015-09-14 16:52:00 |
| Fuzzo        | 2015-02-06 12:12:00 |
| Happy        | 2016-03-17 14:09:00 |
| Puppy        | 2016-03-11 15:43:00 |
| Queens       | 2014-12-03 15:15:00 |
| Elijah       | 2015-09-10 13:14:00 |
| Shadow       | 2014-01-26 13:48:00 |
| Faith        | 2015-05-08 18:34:00 |
| Sammy        | 2017-04-21 11:33:00 |
| Kia          | 2015-08-26 11:51:00 |
| Ariel        | 2014-05-02 12:16:00 |
| Tux          | 2014-12-11 11:48:00 |
| Bj           | 2016-05-08 12:57:00 |
| Peanutbutter | 2015-07-09 17:51:00 |
| Gia          | 2017-04-13 16:29:00 |
| Harley       | 2014-08-08 04:20:00 |
| Meo          | 2017-03-06 15:01:00 |
| Jewel        | 2017-08-13 13:50:00 |
| Sugar        | 2018-01-22 14:32:00 |
```
