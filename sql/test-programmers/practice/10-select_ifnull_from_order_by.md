* Draft: 2020-11-28 (Sat)

[코딩테스트 연습](https://programmers.co.kr/learn/challenges) > [IS NULL](https://programmers.co.kr/learn/challenges?selected_part_id=17045) > [NULL 처리하기](https://programmers.co.kr/learn/courses/30/lessons/59410)

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

입양 게시판에 동물 정보를 게시하려 합니다. 동물의 **생물 종, 이름, 성별 및 중성화 여부를 아이디 순으로 조회**하는 SQL문을 작성해주세요. 이때 프로그래밍을 모르는 사람들은 NULL이라는 기호를 모르기 때문에, **이름이 없는 동물의 이름은 No name으로 표시**해 주세요.

##### 예시

예를 들어 `ANIMAL_INS` 테이블이 다음과 같다면

| ANIMAL_ID | ANIMAL_TYPE | DATETIME            | INTAKE_CONDITION | NAME  | SEX_UPON_INTAKE |
| --------- | ----------- | ------------------- | ---------------- | ----- | --------------- |
| A350276   | Cat         | 2017-08-13 13:50:00 | Normal           | Jewel | Spayed Female   |
| A350375   | Cat         | 2017-03-06 15:01:00 | Normal           | Meo   | Neutered Male   |
| A368930   | Dog         | 2014-06-08 13:20:00 | Normal           | NULL  | Spayed Female   |

마지막 줄의 개는 이름이 없기 때문에, 이 개의 이름은 No name으로 표시합니다. 따라서 SQL문을 실행하면 다음과 같이 나와야 합니다.

| ANIMAL_TYPE | NAME    | SEX_UPON_INTAKE |
| ----------- | ------- | --------------- |
| Cat         | Jewel   | Spayed Female   |
| Cat         | Meo     | Neutered Male   |
| Dog         | No name | Spayed Female   |

※ 컬럼 이름은 일치하지 않아도 됩니다.

------

본 문제는 [Kaggle의 Austin Animal Center Shelter Intakes and Outcomes](https://www.kaggle.com/aaronschlegel/austin-animal-center-shelter-intakes-and-outcomes)에서 제공하는 데이터를 사용하였으며 [ODbL](https://opendatacommons.org/licenses/odbl/1.0/)의 적용을 받습니다.

## 힌트

```sql
SELECT ANIMAL_TYPE, NAME, SEX_UPON_INTAKE FROM ANIMAL_INS ORDER BY ANIMAL_ID;
```

`NAME`에 값이 없는 경우가 있다.

```sql
| ANIMAL_TYPE | NAME         | SEX_UPON_INTAKE |
| ----------- | ------------ | --------------- |
| Cat         | Sugar        | Neutered Male   |
| Cat         | Jewel        | Spayed Female   |
  ...
| Dog         |              | Spayed Female   |
  ...
| Dog         | Rocky        | Neutered Male   |
```

구글 검색: sql replace null to value in mysql

[4 Ways to Replace NULL with a Different Value in MySQL](https://database.guide/4-ways-to-replace-null-with-a-different-value-in-mysql/)

> - The `IFNULL()` function
>
> - The `COALESCE()` function
> - The `IF()` function combined with the `IS NULL` (or `IS NOT NULL`) operator
> - The `CASE` expression combined with the `IS NULL` (or `IS NOT NULL`) operator
>
> ```sql
> SELECT IFNULL(TaskCode, 'N/A') AS Result FROM Tasks;
> SELECT COALESCE(TaskCode, 'N/A') AS Result FROM Tasks;
> SELECT IF(TaskCode IS NOT NULL, TaskCode, 'N/A') AS Result FROM Tasks;
> SELECT 
>     CASE 
>         WHEN TaskCode IS NOT NULL THEN TaskCode 
>         ELSE 'N/A' 
>     END AS Result
> FROM Tasks;
> ```
>
> ```sql
> +--------+
> | Result |
> +--------+
> | gar123 |
> | N/A    |
> | N/A    |
> | dog456 |
> | N/A    |
> | cat789 |
> +--------+
> ```

## 정답

`NAME`에 `IFNULL`함수를 쓰는 명령어 입니다.

```sql
SELECT ANIMAL_TYPE, IFNULL(NAME, 'No name'), SEX_UPON_INTAKE FROM ANIMAL_INS ORDER BY ANIMAL_ID;
```

출력 중 `NULL`이 `No name`으로 변경되었음을 확인할 수 있습니다.

```sqls
| ANIMAL_TYPE | IFNULL(NAME, 'No name') | SEX_UPON_INTAKE |
| ----------- | ----------------------- | --------------- |
| Cat         | Sugar                   | Neutered Male   |
| Cat         | Jewel                   | Spayed Female   |
  ...
| Dog         | No name                 | Spayed Female   |
  ...
| Dog         | Rocky                   | Neutered Male   |
```