import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;


public class TestPredominantEmotion {

    @Test
    public void Test_PredominantEmotionOneEmotion(){
        List<Emotion> lEmotions = new ArrayList<>();
        Emotion e1 = new Emotion("Anger", EmotionType.Anger);
        lEmotions.add(e1);
        Emotion e2 = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(e2);
        Emotion e3 = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(e3);
        Emotion e4 = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(e4);


        ListEmotions le = new ListEmotions(lEmotions);
        List<Emotion> result = le.predominantEmotion();
        assertEquals(result.size(),2);
    }

    @Test
    public void Test_PredominantEmotionEmptyList(){
        List<Emotion> lEmotions = new ArrayList<>();

        ListEmotions le = new ListEmotions(lEmotions);
        List<Emotion> result = le.predominantEmotion();
        assertEquals(result.size(),0);
    }

    @Test
    public void Test_PredominantEmotionMultipleEmotions(){
        List<Emotion> lEmotions = new ArrayList<>();
        Emotion e1 = new Emotion("Anger", EmotionType.Anger);
        lEmotions.add(e1);
        Emotion e2 = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(e2);
        Emotion e3 = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(e3);
        Emotion e4 = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(e4);
        Emotion e5 = new Emotion("Anger", EmotionType.Anger);
        lEmotions.add(e5);


        ListEmotions le = new ListEmotions(lEmotions);
        List<Emotion> result = le.predominantEmotion();
        assertEquals(result.size(),4);
    }
}
