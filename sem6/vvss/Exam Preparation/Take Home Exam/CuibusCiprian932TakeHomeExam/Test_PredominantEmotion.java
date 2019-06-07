import org.junit.Test;

import java.util.ArrayList;
import static org.junit.Assert.assertEquals;
import java.util.List;

public class Test_PredominantEmotion {


    @Test
    public void Test_DoublePredominantEmotion(){
        List<Emotion> lEmotions = new ArrayList<>();
        Emotion eA = new Emotion("Anger", EmotionType.Anger);
        lEmotions.add(eA);
        Emotion eS = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(eS);
        Emotion eJ = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(eJ);
        Emotion eD = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(eD);
        Emotion eF = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(eF);

        ListEmotions le = new ListEmotions(lEmotions);
        List<Emotion> result = le.predominantEmotion();
        assertEquals(result.size(),4);
    }

    @Test
    public void Test_PredominantJoyEmotion() {
        List<Emotion> lEmotions = new ArrayList<>();
        Emotion eA = new Emotion("Anger", EmotionType.Anger);
        lEmotions.add(eA);
        Emotion eS = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(eS);
        Emotion eJ = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(eJ);
        Emotion eD = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(eD);
        Emotion eF = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(eF);

        ListEmotions le = new ListEmotions(lEmotions);
        List<Emotion> result = le.predominantEmotion();
        assertEquals(result.size(),3);
    }

    @Test
    public void Test_PredominantSadnessEmotion() {
        List<Emotion> lEmotions = new ArrayList<>();
        Emotion eA = new Emotion("Anger", EmotionType.Anger);
        lEmotions.add(eA);
        Emotion eS = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(eS);
        Emotion eJ = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(eJ);
        Emotion eD = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(eD);
        Emotion eF = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(eF);

        ListEmotions le = new ListEmotions(lEmotions);
        List<Emotion> result = le.predominantEmotion();
        assertEquals(result.size(),4);
    }

    @Test
    public void Test_PredominantAngerEmotion() {
        List<Emotion> lEmotions = new ArrayList<>();
        Emotion eA = new Emotion("Anger", EmotionType.Anger);
        lEmotions.add(eA);
        Emotion eS = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(eS);
        Emotion eJ = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(eJ);
        Emotion eD = new Emotion("Anger", EmotionType.Anger);
        lEmotions.add(eD);
        Emotion eF = new Emotion("Fear", EmotionType.Fear);
        lEmotions.add(eF);

        ListEmotions le = new ListEmotions(lEmotions);
        List<Emotion> result = le.predominantEmotion();
        assertEquals(result.size(),2);
    }

    @Test
    public void Test_AllPredominantEmotion() {
        List<Emotion> lEmotions = new ArrayList<>();
        Emotion eA = new Emotion("Anger", EmotionType.Anger);
        lEmotions.add(eA);
        Emotion eS = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(eS);
        Emotion eJ = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(eJ);
        Emotion eD = new Emotion("Disgust", EmotionType.Disgust);
        lEmotions.add(eD);
        Emotion eF = new Emotion("Fear", EmotionType.Fear);
        lEmotions.add(eF);

        ListEmotions le = new ListEmotions(lEmotions);
        List<Emotion> result = le.predominantEmotion();
        assertEquals(result.size(),5);
    }
}
