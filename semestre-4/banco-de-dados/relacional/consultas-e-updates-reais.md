# Consultas e updates

```sql
INSERT INTO emblemas_users (player, emblema_id)
SELECT DISTINCT lp_players.username, lp_permissions.permission
FROM luckperms_user_permissions AS lp_permissions
JOIN luckperms_players AS lp_players ON lp_permissions.uuid = lp_players.uuid
WHERE lp_permissions.permission LIKE 'austv.emblema.%';

UPDATE emblemas_users
SET emblema_id = REPLACE(emblema_id, 'austv.emblema.', '');

SELECT COUNT(*) AS quantidade_emblemas
FROM emblemas_users eu
JOIN emblemas_list el ON eu.emblema_id = el.identificador
WHERE eu.player = 'sacucio' AND el.raridade = 3;


SELECT COUNT(*)
FROM `emblemas_users`
WHERE player = 'WaKaliTe';

CREATE VIEW jogador_pontuacao_emblemas AS
SELECT 
    eu.player,
    SUM(
        CASE 
            WHEN el.raridade = 1 THEN 1 
            WHEN el.raridade = 2 THEN 2 
            WHEN el.raridade = 3 THEN 3 
            WHEN el.raridade = 4 THEN 4 
            WHEN el.raridade = 5 THEN 5 
            WHEN el.raridade = 6 THEN 6 
            ELSE 0 
        END
    ) AS total_pontuacao
FROM 
    emblemas_users eu
JOIN 
    emblemas_list el ON eu.emblema_id = el.identificador
GROUP BY 
    eu.player;


SELECT total_pontuacao 
FROM jogador_pontuacao_emblemas 
WHERE player = ?;
```
