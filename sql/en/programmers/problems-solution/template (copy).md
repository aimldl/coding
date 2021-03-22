* Draft: 2020-11-27 (Fri)

# [SELECT](https://programmers.co.kr/learn/challenges?selected_part_id=17042) > 상위 n개 레코드

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

동물 보호소에 **가장 먼저 들어온 동물의 이름을 조회**하는 SQL 문을 작성해주세요.

##### 예시

예를 들어 `ANIMAL_INS` 테이블이 다음과 같다면

| ANIMAL_ID | ANIMAL_TYPE | DATETIME            | INTAKE_CONDITION | NAME     | SEX_UPON_INTAKE |
| --------- | ----------- | ------------------- | ---------------- | -------- | --------------- |
| A399552   | Dog         | 2013-10-14 15:38:00 | Normal           | Jack     | Neutered Male   |
| A379998   | Dog         | 2013-10-23 11:42:00 | Normal           | Disciple | Intact Male     |
| A370852   | Dog         | 2013-11-03 15:04:00 | Normal           | Katie    | Spayed Female   |
| A403564   | Dog         | 2013-11-18 17:03:00 | Normal           | Anna     | Spayed Female   |

이 중 가장 보호소에 먼저 들어온 동물은 Jack입니다. 따라서 SQL문을 실행하면 다음과 같이 나와야 합니다.

| NAME |
| ---- |
| Jack |

※ 보호소에 가장 먼저 들어온 동물은 한 마리인 경우만 테스트 케이스로 주어집니다.

------

본 문제는 [Kaggle의 Austin Animal Center Shelter Intakes and Outcomes](https://www.kaggle.com/aaronschlegel/austin-animal-center-shelter-intakes-and-outcomes)에서 제공하는 데이터를 사용하였으며 [ODbL](https://opendatacommons.org/licenses/odbl/1.0/)의 적용을 받습니다.

## Solution

```sql
SELECT NAME FROM ANIMAL_INS ORDER BY DATETIME LIMIT 1;
```

## Hint

> Source: [SQL TOP, LIMIT or ROWNUM Clause](https://www.w3schools.com/sql/sql_top.asp), w3schools.com
>
> ### Syntax (MySQL)
>
> ```sql
> SELECT column_name(s)
> FROM table_name
> WHERE condition
> LIMIT number;
> ```
>
> ### Examples
>
> ```sql
> SELECT * FROM Customers WHERE Country='Germany' LIMIT 3;
> ```
>
> Source: [SQL | Top-N Queries](https://www.geeksforgeeks.org/sql-top-n-queries/), GeeksforGeeks
>
> TODO:
>
> 

## Result

```sql
| NAME |
| ---- |
| Jack |
```

## Comment

* 실제로는 `DATETIME`의 값을 봐야 가장 먼저 들어왔는지 확인할 수 있습니다. 
  * 그러므로 정답 제출 전에 이 값을 보고
  * 삭제하고 제출합니다.

```sql
SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY DATETIME LIMIT 1;
```

### Result

| NAME | DATETIME            |
| ---- | ------------------- |
| Jack | 2013-10-14 15:38:00 |