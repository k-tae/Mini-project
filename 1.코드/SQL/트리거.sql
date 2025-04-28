BEGIN
    IF NEW.humi > 50 THEN
        INSERT INTO event_log (event_type) VALUES ('HIGH_HUMIDITY');
    END IF;
END


//

DELIMITER ;