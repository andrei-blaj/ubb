import java.lang.reflect.Array;
import java.util.*;

public class ListEmotions {

    private List<Emotion> lstEmotions;

    public ListEmotions(List<Emotion> newLstEmotions){
        this.lstEmotions = newLstEmotions;
    }

    public int getNumberOfEmotions(){
        return lstEmotions.size();
    }

    // Task A_1
    // return the number of emotion of the given EmotionType et
    // Remark: No test cases are going to be created.
    public int howGivenManyEmotionTypeInListEmotions(EmotionType et) {
        int nJE=0;
        //Add code here

        for (Emotion emotion: lstEmotions) {
            if (emotion.getEmotionType().equals(et)) {
                nJE++;
            }
        }

        return nJE;
    }

    // Task A_2
    // return the list of predominante  emotions
    // Remark: Create a set of test cases to assess the correctness of your code.
    //         Create a class to test this method, several test cases are needed.
    //         One sample test case is provided in cladd Test_ListEmotions.
    public List<Emotion> predominantEmotion() {
        List<Emotion> lstEPredominant = new ArrayList<>();
        //Add code here

        Map<EmotionType, Integer> emotionsCount = new HashMap<>();

        emotionsCount.put(EmotionType.Joy, 0);
        emotionsCount.put(EmotionType.Anger, 0);
        emotionsCount.put(EmotionType.Sadness, 0);
        emotionsCount.put(EmotionType.Disgust, 0);
        emotionsCount.put(EmotionType.Fear, 0);

        for (Emotion emotion: this.lstEmotions) {
            emotionsCount.put(emotion.getEmotionType(), emotionsCount.get(emotion.getEmotionType()) + 1);
        }

        int max = Collections.max(emotionsCount.values());

        for(EmotionType emotionType: emotionsCount.keySet()) {
            if(emotionsCount.get(emotionType) == max && max != 0) {
                for (Emotion emotion: this.lstEmotions) {
                    if (emotionType.equals(emotion.getEmotionType())) {
                        lstEPredominant.add(emotion);
                    }
                }
            }
        }

        return lstEPredominant;
    }

    // Task A_3
    // Eliminate the emotions that are of given type EmotionType et
    // Remark: A set of test cases to assess the correctness of your code is provided.
    //         A class to test this method was created, several test cases were added.
    //         Use the test cases to check for your code.
    public void eliminateAllProvidedEmotion(EmotionType et) {
        //Add code here

        List<Emotion> emotionList = new ArrayList<>();

        for (Emotion emotion : lstEmotions) {
            if (emotion.getEmotionType() != et) {
                emotionList.add(emotion);
            }
        }

        lstEmotions = emotionList;

    }
}
