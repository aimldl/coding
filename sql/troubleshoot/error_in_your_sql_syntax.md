* Draft: 2020-11-27 (Fri)

# You have an error in your SQL syntax

## 문제: Top N 결과 조회

* 동물 보호소에 가장 먼저 들어온 동물의 이름을 조회하는 SQL 문을 작성하려고 합니다.

* Top N 결과 조회 문제 중 N=1인 경우입니다.
* 문제의 출처: [프로그래머스](https://programmers.co.kr/) > [코딩테스트 연습](https://programmers.co.kr/learn/challenges) > [SELECT](https://programmers.co.kr/learn/challenges?selected_part_id=17042) > [상위 n개 레코드](https://programmers.co.kr/learn/courses/30/lessons/59405)

### 테이블 구조

| NAME             | TYPE       | NULLABLE |
| ---------------- | ---------- | -------- |
| ANIMAL_ID        | VARCHAR(N) | FALSE    |
| ANIMAL_TYPE      | VARCHAR(N) | FALSE    |
| DATETIME         | DATETIME   | FALSE    |
| INTAKE_CONDITION | VARCHAR(N) | FALSE    |
| NAME             | VARCHAR(N) | TRUE     |
| SEX_UPON_INTAKE  | VARCHAR(N) | FALSE    |

### 예시

| ANIMAL_ID | ANIMAL_TYPE | DATETIME            | INTAKE_CONDITION | NAME     | SEX_UPON_INTAKE |
| --------- | ----------- | ------------------- | ---------------- | -------- | --------------- |
| A399552   | Dog         | 2013-10-14 15:38:00 | Normal           | Jack     | Neutered Male   |
| A379998   | Dog         | 2013-10-23 11:42:00 | Normal           | Disciple | Intact Male     |
| A370852   | Dog         | 2013-11-03 15:04:00 | Normal           | Katie    | Spayed Female   |
| A403564   | Dog         | 2013-11-18 17:03:00 | Normal           | Anna     | Spayed Female   |

### 기대하는 결과

| NAME |
| ---- |
| Jack |

## 명령어

이 명령어를 입력하면

```sql
SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY DATETIME;
```

순서대로 잘 나오는데

| NAME     | DATETIME            |
| -------- | ------------------- |
| Jack     | 2013-10-14 15:38:00 |
| Disciple | 2013-10-23 11:42:00 |
| ...      | ...                 |
| Stormy   | 2018-02-03 10:40:00 |

이 결과를 받아서 Nested inline으로 처리하면 

```sql
SELECT NAME, ROWNUM as RANK FROM ( SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY DATETIME ) WHERE ROWNUM <=1;
```

에러가 발생합니다.

## 에러

```sql
SQL 실행 중 오류가 발생하였습니다.
You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'RANK FROM ( SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY DATETIME ) WHERE ROWN' at line 2
```

## 힌트

`ROWNUM`이 문제인가 해서 `NAME`으로 `WHERE`문을 구성해봐도

```sql
SELECT NAME as RANK FROM ( SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY DATETIME ) WHERE NAME = 'Jack';
```

유사한 에러가 발생합니다.

```sql
SQL 실행 중 오류가 발생하였습니다.
You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'RANK FROM ( SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY DATETIME ) WHERE NAME' at line 1
```

## 이유

* 이렇게 `FROM`구에서 서브쿼리를 사용하고 `WHERE`구에서 `ROWNUM`를 쓰는 것은 Oracle용 문법입니다.
* 에러 메세지를 보면 MySQL서버임을 알 수 있습니다.

## 해결책

MySQL에선 `LIMIT`구를 쓰게 됩니다. 원래 명령어의 첫 번째 서브쿼리 끝에 `LIMIT N`을 추가하면 됩니다. `N=1`이므로

```sql
SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY DATETIME LIMIT 1;
```

를 실행하며 아래와 같은 결과를 얻습니다.

| NAME | DATETIME            |
| ---- | ------------------- |
| Jack | 2013-10-14 15:38:00 |

`NAME`만 출력하고 싶은 경우엔

```sql
SELECT NAME FROM ANIMAL_INS ORDER BY DATETIME LIMIT 1;
```

를 실행하면 아래의 결과를 얻게 됩니다.

| NAME |
| ---- |
| Jack |

## 참고 서적

*  "11강. 결과 행 제한하기 - LIMIT", SQL 첫걸음, pp.108-113, 한빛미디어